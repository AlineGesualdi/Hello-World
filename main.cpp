#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include "hellowmainwindow.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int widthDesktop = a.desktop()->width(); // returns screen width
    int heightDesktop = a.desktop()->height();  // returns screen height
    std::cout << "widthDesktop: " << widthDesktop << " heightDesktop: " << heightDesktop << std::endl;

    HelloWMainWindow w;
    w.setFixedSize(a.desktop()->size());
    w.showFullScreen();
    w.calcScreenCenter(widthDesktop,heightDesktop);

    return a.exec();
}
