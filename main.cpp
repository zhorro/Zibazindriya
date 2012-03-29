#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "podcastsdb.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    pdb.start();
    pdb.wait();

    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/Ziba_from_the_other_side/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
