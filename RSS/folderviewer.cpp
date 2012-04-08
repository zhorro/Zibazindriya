#include "folderviewer.h"

FolderViewer::FolderViewer(QObject *parent) :
    QAbstractListModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[StatusRole] = "status";
    roles[DownlRole] = "dowloadedItems";
    roles[NewRole] = "updatedItems";
    roles[DescRole] = "description";
    setRoleNames(roles);
}

int FolderViewer::rowCount( const QModelIndex & parent )  const
{
	return 10;
}

QVariant FolderViewer::data ( const QModelIndex & index, int role )  const
{
	switch ( role )
	{
	case DownlRole :
		return QVariant(index.row());
		break;
	case NewRole :
		return QVariant(rowCount()-index.row());
		break;
	}
	return QVariant(QString("Unimplemented yet!"));
}
