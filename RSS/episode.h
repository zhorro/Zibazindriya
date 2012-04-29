#ifndef EPISODE_H
#define EPISODE_H

#include <QFileInfo>
#include <QUrl>
#include <QObject>
#include <QDateTime>
#include <QString>

#include <QMetaType>

class Episode : public QObject
{
	Q_OBJECT

public:
	Episode(QObject *parent = NULL);
	Episode(const Episode &);
	~Episode();

	int id;
	QFileInfo local;	// Файл
	QUrl url;			// ссылка в интернете
	int podcast;		// id подкаста

	bool newEpisode;
	bool downloaded;
	bool stillInFeed;

	QDateTime timeUpdated;
	QDateTime timeDownloaded;
	QDateTime created;
	QDateTime deleteAfter;

	double duration;
	double lastPlayedPosition;

	QString title;       
	QString GUID;      
	QString description;     
	QString shownotes;    
	QString src;   
	QString link;  

	bool updating;

	static QString dbCreationString();

private:

};

Q_DECLARE_METATYPE (Episode);

#endif // EPISODE_H
