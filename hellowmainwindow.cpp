#include "hellowmainwindow.h"
#include "ui_hellowmainwindow.h"

HelloWMainWindow::HelloWMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelloWMainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
}

HelloWMainWindow::~HelloWMainWindow()
{
    delete ui;
}

void HelloWMainWindow::buttonClickHandler()
{
    ui->label->setText(ui->lineEdit->text());
}

void HelloWMainWindow::buttonClicked()
{

}

void HelloWMainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
            case Qt::Key_Escape:
                    QApplication::exit();
                    break;
            case Qt::Key_Enter:
                    buttonClicked();
                    break;
            default:
                    QWidget::keyPressEvent(event);
    }
}
