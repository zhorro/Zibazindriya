#ifndef FOLDERVIEWER_H
#define FOLDERVIEWER_H

#include <QSqlQueryModel>

class FolderViewer : public QSqlQueryModel
{
    Q_OBJECT
public:
    enum FolderRoles {
        rl_status = Qt::UserRole + 1,
        rl_downloaded,
        rl_newEpisodes,
        rl_description,
        rl_url,
    };

    explicit FolderViewer(QObject *parent = 0);

    QVariant 	data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
signals:
    
public slots:

};

#endif // FOLDERVIEWER_H
