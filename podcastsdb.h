#ifndef PODCASTSDB_H
#define PODCASTSDB_H

#include <QtSql>
#include <QUrl>

const QString ziba_dbaseName = "zibaDB.sqlite";
class  podcastsDB : public QObject
{
    Q_OBJECT
public:
    explicit podcastsDB(QObject *parent = 0);
    ~podcastsDB();

	bool exists (QUrl); // Проверяет наличие в базе такого источника подкастов
	void append (QUrl); // Добавляет в базу новый источник

signals:
	void gotNewSources();

private:
    QSqlDatabase dbase;
};


#endif // PODCASTSDB_H
