#include <QtGui/QApplication>
#include <QDeclarativeContext>
#include <QList>
#include "qmlapplicationviewer.h"

#include "RSS/rssbaseitem.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("QML/Zibazindriya.qml"));

    QList<QObject*> rssModel;
    rssModel.append(new rssBaseItem());
    rssModel.append(new rssBaseItem());
    rssModel.append(new rssBaseItem());

    QDeclarativeContext *ctxt = viewer.rootContext();
    ctxt->setContextProperty("feedsModel", QVariant::fromValue(rssModel));

    viewer.showExpanded();

    return app->exec();
}
