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

    myList << "Hello 1" << "Hello 2" << "Hello 3";

    ui->label->hide();

    mytimer = new QTimer(this);
    connect(mytimer, SIGNAL(timeout()), this, SLOT(showLabel()));
    mytimerBlank = new QTimer(this);
    connect(mytimerBlank, SIGNAL(timeout()), this, SLOT(showBlank()));
    mytimer->start(1000);

    counter = 0;
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
    mytimer->stop();
    //std::cout << "myList.size = " << myList.size() <<  "  counter = " << counter << std::endl;
    if(counter < myList.size()-1) counter++;
    else counter = myList.size();
    ui->label->show();
    ui->label->setText(myList[counter-1]);
    mytimerBlank->start(300);
}

void HelloWMainWindow::showBlank()
{
    mytimerBlank->stop();
    ui->label->hide();
    mytimer->start(1000);
}

void HelloWMainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
            case Qt::Key_Escape:
                    QApplication::exit();
                    break;
            case Qt::Key_Space:

                    break;
            default:
                    QWidget::keyPressEvent(event);
    }
}
