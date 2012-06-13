#include <QtGui/QApplication>
#include <QDeclarativeContext>
#include <QList>
#include "qmlapplicationviewer.h"

#include "RSS/folderviewer.h"
#include "podcastsdb.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
	podcastsDB pdb(&viewer);

	FolderViewer foldModel;
	foldModel.setQuery(QSqlQuery("SELECT * FROM podcasts"));

	QDeclarativeContext *ctxt = viewer.rootContext();
	ctxt->setContextProperty("feedsModel", &foldModel);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
#if 0
    viewer.setMainQmlFile(QLatin1String("qml/Zibazindriya.qml"));
#else
    viewer.setMainQmlFile(QLatin1String("qml/ZibaDesktop.qml"));
#endif
    viewer.rootContext()->setContextProperty("Ziba", &pdb);
    viewer.showExpanded();

    return app->exec();
}
