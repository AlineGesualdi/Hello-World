#ifndef HELLOWMAINWINDOW_H
#define HELLOWMAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
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
    ~HelloWMainWindow();

public slots:
    void buttonClickHandler();
    void buttonClicked();

private:
    Ui::HelloWMainWindow *ui;
};

#endif // HELLOWMAINWINDOW_H
