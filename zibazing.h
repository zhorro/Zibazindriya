﻿#ifndef ZIBAZING_H
#define ZIBAZING_H

#include <QObject>
#include <QSettings>
#include <QDir>
#include <QDateTime>
#include <QString>

class zibazing : public QObject
{
    Q_OBJECT
public:
    explicit zibazing(QObject *parent = 0);

// Внутрение шняги
    QDir podcastsDir ();
    QDir workingDir ();
    QString dbaseName();

// Настройки
    QDateTime nextUpdate(); // Когда следуйщий раз всех проапдейтить
    bool downloadShowsAutomatically();
    int  deleteOldShowsInADays();
    int  markShowsAsOldInADays();
    int  updateEveryHours ();


signals:

public slots:
    void updateDone ();
private:
    QSettings set;
};

extern zibazing ziba;

#endif // ZIBAZING_H
