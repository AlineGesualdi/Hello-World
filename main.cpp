#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include "hellowmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    HelloWMainWindow w;
    w.setFixedSize(a.desktop()->size());
    w.showFullScreen();

    return a.exec();
}
