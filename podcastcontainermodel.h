#ifndef PODCASTTAGMODEL_H
#define PODCASTTAGMODEL_H

#include <QObject>

class podcastContainerModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int newPodcast READ getNewPodcast NOTIFY podcastChanges)
    Q_PROPERTY(int downloadedPodcast READ getDownloaded NOTIFY podcastChanges)
    Q_PROPERTY(QString icon READ getIcon NOTIFY podcastChanges)
    Q_PROPERTY(QString description READ getDescription NOTIFY podcastChanges)

public:
    explicit podcastContainerModel(QString tag, QObject *parent = 0);

    int getNewPodcast();
    int getDownloaded();
    QString getIcon();
    QString getDescription();

signals:
    void podcastChanges();

public slots:
    
};

#endif // PODCASTTAGMODEL_H
