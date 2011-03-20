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

    primeList << "Prime 1" << "Prime 2" << "Prime 3";
    targetList << "Target 1" << "Target 2" << "Target 3";

    ui->label->hide();

    mytimer = new QTimer(this);
    connect(mytimer, SIGNAL(timeout()), this, SLOT(showLabel()));
    mytimerBlank = new QTimer(this);
    connect(mytimerBlank, SIGNAL(timeout()), this, SLOT(showBlank()));
    mytimer->start(1000);

    counter = 0;
    flagPrime = false;
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
    if(counter < primeList.size()-1) counter++;
    else counter = primeList.size();

    if(flagPrime == false) { ui->label->setText(primeList[counter-1]); counter--; }
    if(flagPrime == true) ui->label->setText(targetList[counter-1]);


    ui->label->show();
    mytimerBlank->start(300);
}

void HelloWMainWindow::showPrime(int count)
{

}

void HelloWMainWindow::showTarget(int count)
{

}

void HelloWMainWindow::showBlank()
{
    if(flagPrime == false) flagPrime = true;
    else flagPrime = false;
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
