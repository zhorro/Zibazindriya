#include <qxml.h>
#include <qdebug.h>
#include <QDateTime>
#include <QUrl>

#include "rssParser.h"

rssParser::rssParser (int pod, QByteArray xml, QObject * parent)
	: QObject (parent)
	, podcast(pod)
{
    errorParsingXML = false;
    QString error;
    int line, column;

    if (!doc.setContent(xml, true, &error, &line, &column))
    {
        qDebug() << xml << endl << "Parsing XML error: " << error << " at line:" << line << " column: " << column;
        errorParsingXML = true;
    }
}

void rssParser::extractTitle()
{
    // Зафигачить тайтл
    QDomElement T = doc.documentElement().firstChildElement("channel").firstChildElement("title");
    if(!T.isNull())
    {
        QString title = T.text();
        qDebug() << "got new title: " << title;
		emit gotTitle(podcast, title);
    }
    else
        errorParsingXML = true;
}

void rssParser::extractImage()
{
    // Зафигачить ссылку на картинку
    QDomElement T = doc.documentElement().firstChildElement("channel").firstChildElement("image").firstChildElement("url");
    if(!T.isNull())
    {
        QUrl imageUrl = QUrl(T.text());
        qDebug() << "got new image Url: " << imageUrl;
		emit gotImage(podcast, imageUrl);
    }
    else
        errorParsingXML = true;
}

void rssParser::extractItems()
{
    QDomElement T = doc.documentElement().firstChildElement("channel");
    if(!T.isNull())
    {
        QDomNodeList il = T.elementsByTagName ("item");
        for (int i = 0; i < il.count(); i++)
            parseItem(il.at(i));
    }
    else
        errorParsingXML = true;
}

void rssParser::parseItem( const QDomNode n )
{
    Episode item;
    item.title        = n.firstChildElement("title").text();
    item.description  = n.firstChildElement("description").text();
    item.created      = timeParser(n.firstChildElement("pubDate").text());
    item.url		  = QUrl(n.firstChildElement("link").text());
    item.local        = QFileInfo(n.firstChildElement("enclosure").attribute("url"));
    
	emit gotNewEpisode(podcast, item);
}

QDateTime rssParser::timeParser(QString pubDateString )
{
    QString tryParseDate = pubDateString.left(QString("ddd, dd MMM yyyy HH:mm:ss").length());
    QDateTime pubDate = QDateTime::fromString(tryParseDate, "ddd, dd MMM yyyy HH:mm:ss");

    if (!pubDate.isValid()) {
        qWarning() << "Could not parse pubDate for podcast episode!";
        pubDate = QDateTime::currentDateTime();
    }

    return pubDate;
}

bool rssParser::go()
{
	extractTitle();
	extractImage();
	extractItems();

	return errorParsingXML;
}
