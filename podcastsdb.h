#ifndef PODCASTSDB_H
#define PODCASTSDB_H

#include <QtSql>
#include <QUrl>
#include <QQueue>
#include <QPair>
#include <QNetworkAccessManager>
#include <QList>

#include "RSS/episode.h"

const QString ziba_dbaseName = "zibaDB.sqlite";
class  podcastsDB : public QObject
{
    Q_OBJECT
public:
    enum getModes {
		gmScanForNewPodcasts,
		gmDownloadIcon,
		gmDownloadAudio,
        gmDownloadShownotes
	};

    explicit podcastsDB(QObject *parent = 0);
    ~podcastsDB();

	int  exists (QUrl); // Проверяет наличие в базе такого источника подкастов, если есть то возвращаем его id, иначе -1
	void append (QUrl); // Добавляет в базу новый источник
	void scan	(QUrl); // Сканирует QUrl на предмет новых записей
	void scanAll();		// Сканирует всё на предмет новых записей

signals:
	void gotNewSources();

public slots:
	void replyFinishedScan ( );
	void scanQueue ();
	void cleanRelays();

	void gotNewEpisode (int podcast, Episode item);

private:
    QSqlDatabase dbase;
    QNetworkAccessManager * manager;
	QList<QNetworkReply *> replys;
    QQueue<QPair<QUrl, getModes> > getsQueue;

	void get ( QUrl url, getModes mode );
	void post( QUrl url, getModes mode );
};


#endif // PODCASTSDB_H
