#ifndef HELLOWMAINWINDOW_H
#define HELLOWMAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include <QStringList>
#include <QString>
#include <ctype.h>

namespace Ui {
    class HelloWMainWindow;
}

class HelloWMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelloWMainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *k);
    void calcScreenCenter(int widthDesktop, int heightDesktop);
    ~HelloWMainWindow();

public slots:
    void showLabel();
    void showBlank();

private:
    Ui::HelloWMainWindow *ui;
    QTimer *mytimer, *mytimerBlank;
    QStringList myList;
    QString listItem;
    int counter;
};

#endif // HELLOWMAINWINDOW_H
