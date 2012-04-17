#include <QtSql>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "podcastsdb.h"
#include "opmlimport.h"

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
	if (queryOfCreatingPeredachki.exec (
		"CREATE TABLE episode ("
		"id                 INTEGER     PRIMARY KEY,"
		"local              TEXT,"
		"url                TEXT,"
		"podcast            INTEGER,"

		"new                BOOLEAN,"
		"downloaded         BOOLEAN,"
		"stillInFeed        BOOLEAN,"

		"timeUpdated		TIME,"
		"timeDownloaded		TIME,"
		"created            TIME,"
		"deleteAfter        TIME,"

		"duration           DOUBLE,"
		"lastPlayedPosition DOUBLE,"

		"title              TEXT,"
		"GUID               TEXT,"
		"description        TEXT,"
		"shownotes          TEXT,"
		"src                TEXT,"
		"link               TEXT,"

		"updating           BOOLEAN"
		")"))
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
}

podcastsDB::~podcastsDB()
{
	dbase.close();
	QSqlDatabase::removeDatabase(ziba_dbaseName);
}


bool podcastsDB::exists (QUrl url)
{
	QSqlQuery query("SELECT * FROM podcasts WHERE "
		"podcast = ?");
	query.addBindValue(url);
	query.exec();

	if (query.next())
		return true;
	return false;
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

void podcastsDB::scan (QUrl url) // Сканирует QUrl на предмет новых записей
{
	get(url, getModes::gmScanForNewPodcasts);
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
		auto q = getsQueue.dequeue();
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
	QNetworkRequest req(url);
	QNetworkReply *reply = manager->get(req);
	switch (mode)
	{
		case getModes::gmScanForNewPodcasts : 
			connect(reply, SIGNAL(finished()), this, SLOT(replyFinishedScan()));
			break;
		case getModes::gmDownloadIcon:
		case getModes::gmDownloadAudio:
		case getModes::gmDownloadShownotes:
		default :
		qDebug () << "Unimplemented get mode";
	}
	replys << reply;
}

void podcastsDB::replyFinishedScan ( QNetworkReply * reply )
{
	if (reply) 
	{
		if (reply->error() == QNetworkReply::NoError) 
		{
			//read data from reply
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
