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
    
    roles[rl_url        ] = "mdl_url";

	roles[rl_title]       = "mdl_title";
	roles[rl_icon]		  =	"mdl_icon";
	roles[rl_tag]		  =	"mdl_tag";
	roles[rl_deleteInDays]=	"mdl_deleteInDays";

    setRoleNames(roles);
}

QVariant FolderViewer::data ( const QModelIndex & index, int role )  const
{
// 	for (int i = 0; i < columnCount(); i++)
// 	{
// 		qDebug() << i << " : " << headerData(i, Qt::Horizontal);
// 	}
    QVariant res (QString("Unimplemented yet!"));
    switch ( role )
    {
    case rl_title:
        res = QSqlQueryModel::data(index.sibling(index.row(), 1), Qt::DisplayRole);
        break;
    case rl_url :
        res = QSqlQueryModel::data(index.sibling(index.row(), 2), Qt::DisplayRole);
        break;
	case rl_icon:
        res = QSqlQueryModel::data(index.sibling(index.row(), 3), Qt::DisplayRole);
        break;
    case rl_tag:
        res = QSqlQueryModel::data(index.sibling(index.row(), 4), Qt::DisplayRole);
        break;
    case rl_deleteInDays:
        res = QSqlQueryModel::data(index.sibling(index.row(), 5), Qt::DisplayRole);
        break;
    case rl_status:
        res = QSqlQueryModel::data(index.sibling(index.row(), 6), Qt::DisplayRole);
        break;
    case rl_newEpisodes:
    case rl_downloaded:
        break;
    }
    qDebug() << "role: " << role << " : " << res.toString();
    return res;
}
