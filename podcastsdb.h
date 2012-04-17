#ifndef PODCASTSDB_H
#define PODCASTSDB_H

#include <QtSql>
#include <QUrl>
#include <QQueue>
#include <QPair>
#include <QNetworkAccessManager>
#include <QList>

const QString ziba_dbaseName = "zibaDB.sqlite";
class  podcastsDB : public QObject
{
    Q_OBJECT
	enum getModes {
		gmScanForNewPodcasts,
		gmDownloadIcon,
		gmDownloadAudio,
		gmDownloadShownotes,
	};
public:
    explicit podcastsDB(QObject *parent = 0);
    ~podcastsDB();

	bool exists (QUrl); // Проверяет наличие в базе такого источника подкастов
	void append (QUrl); // Добавляет в базу новый источник
	void scan	(QUrl); // Сканирует QUrl на предмет новых записей

signals:
	void gotNewSources();

public slots:
	void replyFinishedScan ( QNetworkReply * reply );
	void scanQueue ();
	void cleanRelays();

private:
    QSqlDatabase dbase;
    QNetworkAccessManager * manager;
	QList<QNetworkReply *> replys;
	QQueue<QPair<QUrl, getModes>> getsQueue;

	void get ( QUrl url, getModes mode );
	void post( QUrl url, getModes mode );
};


#endif // PODCASTSDB_H
