#include <QDebug>
#include <QUrl>
#include "folderviewer.h"

FolderViewer::FolderViewer(QObject *parent) :
    QSqlQueryModel(parent)
{	
    QHash<int, QByteArray> roles;
    roles[StatusRole] = "status";
    roles[DownlRole] = "dowloadedItems";
    roles[NewRole] = "updatedItems";
    roles[DescRole] = "descr";
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
	case DescRole :
		{
			QString desc = QSqlQueryModel::data(index.sibling(index.row(), 1), Qt::DisplayRole).toString();
			QUrl    url  = QSqlQueryModel::data(index.sibling(index.row(), 2), Qt::DisplayRole).toString();
			return 	desc.isEmpty() ? url : desc;
		}
		break;
	case NewRole :
		return QVariant(rowCount()-index.row());
		break;
	}
	return QVariant(QString("Unimplemented yet!"));
}
