﻿#include <QtGui/QApplication>
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
	QDeclarativeContext *ctxt = viewer.rootContext();
	ctxt->setContextProperty("feedsModel", &foldModel);

	
	viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
	viewer.setMainQmlFile(QLatin1String("QML/Zibazindriya.qml"));
	viewer.showExpanded();

    return app->exec();
}
