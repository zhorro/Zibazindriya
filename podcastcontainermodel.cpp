#include "podcastcontainermodel.h"

podcastContainerModel::podcastContainerModel(QString tag, QObject *parent) :
    QObject(parent)
{

}


int podcastContainerModel::getNewPodcast()
{
    return 0;
}

int podcastContainerModel::getDownloaded()
{
    return 0;
}

QString podcastContainerModel::getIcon()
{
    return QString("");
}

QString podcastContainerModel::getDescription()
{
    return QString("");
}

