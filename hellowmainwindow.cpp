#include "hellowmainwindow.h"
#include "ui_hellowmainwindow.h"

HelloWMainWindow::HelloWMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelloWMainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
    mytimer = new QTimer(this);
    connect(mytimer, SIGNAL(timeout()), this, SLOT(showLabel()));
    myList << "aline" << "alex" << "maria fernanda";
}

HelloWMainWindow::~HelloWMainWindow()
{
    delete ui;
}

void HelloWMainWindow::buttonClickHandler()
{
    ui->label->setText(ui->lineEdit->text());
    //ui->label->setText(myList[2]);
    mytimer->start(1000);
    ui->label->hide();
}

void HelloWMainWindow::showLabel()
{
    ui->label->show();
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
