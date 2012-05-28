#include <QtSql>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "podcastsdb.h"
#include "opmlimport.h"
#include "RSS/episode.h"
#include "RSS/rssParser.h"

podcastsDB::podcastsDB(QObject *parent) :
QObject(parent)
{
	static int instance = 0;
	Q_ASSERT(instance++==0);
	bool recreated = false;

	manager = new QNetworkAccessManager(this);

	dbase = QSqlDatabase::addDatabase("QSQLITE");
	dbase.setDatabaseName(ziba_dbaseName);

	if (!dbase.open()) {
		qDebug() << "ААаааа!!   Где моя базочка!!!";
		throw QString ("Не открывается база");
	}

	QSqlQuery queryOfCreatingPeredachki(dbase);
	if (queryOfCreatingPeredachki.exec ( Episode::dbCreationString()))
	{
		recreated = true;
		qDebug () << "TABLE episode successfully created";
	}
	else
		qDebug () << "TABLE episode not created: " << queryOfCreatingPeredachki.lastError ();

	QSqlQuery queryOfCreatingSources(dbase);
	if (queryOfCreatingSources.exec (
		"CREATE TABLE podcasts ("
		"id                 INTEGER     PRIMARY KEY,"
		"title              TEXT,"
		"podcast            TEXT,"
		"icon               TEXT,"
		"tag				TEXT,"
		"deleteInDays       INTEGER"
		")"))
	{
		recreated = true;
		qDebug () << "TABLE podcasts successfuly created";
	}
	else
		qDebug () << "TABLE podcasts not created: " << queryOfCreatingSources.lastError ();

	//if (recreated)
	OPMLImport("opml/defaultFeeds.opml", this);
	scanAll();
}

podcastsDB::~podcastsDB()
{
	dbase.close();
	QSqlDatabase::removeDatabase(ziba_dbaseName);
}


int podcastsDB::exists (QUrl url)
{
	QSqlQuery query("SELECT * FROM podcasts WHERE "
		"podcast = ?");
	query.addBindValue(url);
	query.exec();

	if (query.next())
		return query.value(query.record().indexOf("id")).toInt();
	return 0;
}

void podcastsDB::append (QUrl url)
{
	qDebug() << "Appending source = " << url.toString();
	QSqlQuery query("INSERT INTO podcasts (podcast) "
		"VALUES (?)");
	query.addBindValue(url);
	if (!query.exec())
		qDebug() << "error appending. SQL:" << query.executedQuery() << "error"<< query.lastError();

	emit gotNewSources();
}

void podcastsDB::scanAll()
{
	QSqlQuery query("SELECT * FROM podcasts"); // Выбрать все подкасты
	const int fieldNo = query.record().indexOf("podcast");
	while (query.next())
		scan(query.value(fieldNo).toUrl());
}

void podcastsDB::scan (QUrl url) // Сканирует QUrl на предмет новых записей
{
	qDebug() << "appending to scan queue url: " << url.toString();
    get(url, gmScanForNewPodcasts);
}

void podcastsDB::post( QUrl url, getModes mode )
{
	getsQueue << qMakePair (url, mode);
	emit scanQueue();
}

void podcastsDB::scanQueue ()
{
	cleanRelays();
	if (replys.count() < 10)
	{
        QPair<QUrl, getModes> q = getsQueue.dequeue();
		get(q.first, q.second);
	}
}

void podcastsDB::cleanRelays()
{
	int i = 0;
	while (i < replys.count())
	{
		QNetworkReply * r = qobject_cast <QNetworkReply *> (replys[i]);
		if (r)
		{
			i++;
			continue;
		}
		replys.removeAt(i);
	}
}

		

void podcastsDB::get( QUrl url, getModes mode )
{
	QNetworkReply *reply = manager->get(QNetworkRequest(url));
	switch (mode)
	{
		case gmScanForNewPodcasts : 
			connect(reply, SIGNAL(finished( )), this, SLOT(replyFinishedScan( )));
			break;
		case gmDownloadIcon:
		case gmDownloadAudio:
		case gmDownloadShownotes:
		default :
		qDebug () << "Unimplemented get mode";
	}
	replys << reply;
}

void podcastsDB::replyFinishedScan ( )
{
	QNetworkReply * reply = qobject_cast<QNetworkReply*>(this->sender());
	if (reply) 
	{
		if (reply->error() == QNetworkReply::NoError) 
		{
			int podcastId = exists(reply->url());

			rssParser rss(podcastId, reply->readAll(), this);
			qDebug() << connect (&rss, SIGNAL(gotNewEpisode(int, Episode)), this, SLOT(gotNewEpisode (int, Episode)), Qt::DirectConnection);
			rss.go();
		} 
		else 
		{	
			//get http status code
			int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
			//do some error management
		}
		reply->deleteLater();
	}
}

void podcastsDB::gotNewEpisode (int podcast, Episode item)
{
	// 1. Проверить наличие эпизода в базе
	//	2. Добавить эпизод в базу
	//	3. Обновить какиенито егоные характеристики
	// QSqlQuery query ("INSERT INTO podcasts (podcast) "
	//	"VALUES (?)");
}

