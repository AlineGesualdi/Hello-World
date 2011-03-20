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
    bool flagPrime;
    Ui::HelloWMainWindow *ui;
    QTimer *mytimer, *mytimerBlank;
    QStringList primeList, targetList;
    QString listItem;
    int counter;
};

#endif // HELLOWMAINWINDOW_H
