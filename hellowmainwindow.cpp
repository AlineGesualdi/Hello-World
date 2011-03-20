#include "hellowmainwindow.h"
#include "ui_hellowmainwindow.h"
#include <iostream>
#include <stdio.h>

HelloWMainWindow::HelloWMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelloWMainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");

    myList << "aline" << "alex" << "maria fernanda";

    ui->label->hide();

    mytimer = new QTimer(this);
    connect(mytimer, SIGNAL(timeout()), this, SLOT(showLabel()));
    mytimer->start(1000);
}

HelloWMainWindow::~HelloWMainWindow()
{
    delete ui;
}

void HelloWMainWindow::calcScreenCenter(int widthDesktop, int heightDesktop)
{
    //	Center position calculation
        int cw = (widthDesktop/2) - (ui->label->width()/2);
        int ch = (heightDesktop/2) - (ui->label->height()/2);
        std::cout << "center width: " << cw << " center height: " << ch << std::endl;
        ui->label->move(cw,ch);
}

void HelloWMainWindow::showLabel()
{
    ui->label->show();
    ui->label->setText(myList[2]);
    mytimer->start(1000);
}

void HelloWMainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
            case Qt::Key_Escape:
                    QApplication::exit();
                    break;
            case Qt::Key_Enter:

                    break;
            default:
                    QWidget::keyPressEvent(event);
    }
}
