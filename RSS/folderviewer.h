#ifndef FOLDERVIEWER_H
#define FOLDERVIEWER_H

#include <QAbstractListModel>

class FolderViewer : public QAbstractListModel
{
    Q_OBJECT
public:
    enum FolderRoles {
        StatusRole = Qt::UserRole + 1,
        DownlRole,
        NewRole,
        DescRole,
    };

    explicit FolderViewer(QObject *parent = 0);

	int 	rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant 	data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
signals:
    
public slots:
    
};

#endif // FOLDERVIEWER_H
