#include <QDebug>
#include <QUrl>
#include "folderviewer.h"

FolderViewer::FolderViewer(QObject *parent) :
    QSqlQueryModel(parent)
{	
    QHash<int, QByteArray> roles;
    roles[rl_status     ] = "status";
    roles[rl_downloaded ] = "mdl_downloaded";
    roles[rl_newEpisodes] = "mdl_newEpisodes";
    roles[rl_description] = "mdl_description";
    roles[rl_url        ] = "mdl_url";
    setRoleNames(roles);
}

void FolderViewer::updateData()
{
    //
}

QVariant FolderViewer::data ( const QModelIndex & index, int role )  const
{
    switch ( role )
    {
    case rl_description :
        return QSqlQueryModel::data(index.sibling(index.row(), 1), Qt::DisplayRole).toString();
    case rl_url :
        return QSqlQueryModel::data(index.sibling(index.row(), 2), Qt::DisplayRole).toString();
    case rl_newEpisodes :
        return QVariant(rowCount()-index.row());
    }
    return QVariant(QString("Unimplemented yet!"));
}
