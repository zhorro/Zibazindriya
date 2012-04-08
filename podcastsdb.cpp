#include <QtSql>

#include "podcastsdb.h"
#include "opmlimport.h"

podcastsDB::podcastsDB(QObject *parent) :
    QObject(parent)
{
	static int instance = 0;
	Q_ASSERT(instance++==0);
	bool recreated = false;

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
        OPMLImport("opml\\defaultFeeds.opml", this);
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

