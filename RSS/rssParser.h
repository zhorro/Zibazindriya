#ifndef RSSCONTAINER_H
#define RSSCONTAINER_H

#include <QByteArray>
#include <QDateTime>

#include <QDomDocument>
#include <QDomNode>

#include <QFile>
#include <QVector>
#include <QObject>
#include <QUrl>

#include "episode.h"

class rssParser : public QObject
{
	Q_OBJECT
public:
    rssParser (int podcast, QByteArray xml, QObject * parent);

	bool go();

signals:
	void gotImage(QUrl);
	void gotTitle(QString);
	void gotLink (QUrl);
	void gotNewEpisode (int, Episode);

private:
    QDomDocument doc;
    bool errorParsingXML;
	int  podcast;

    void extractItems();
    void extractImage();
    void extractTitle();
    void parseItem( const QDomNode n );
    QDateTime timeParser( QString );
};

#endif // RSSCONTAINER_H
