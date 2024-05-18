#ifndef GLOBAL_SETTINGS_H
#define GLOBAL_SETTINGS_H

#include <QWidget>
#include <QMainWindow>
#include "ui_Global_Settings.h"
#include <QStackedWidget>
#include "display.h"
#include "message.h"
#include "routine.h"
#include "traffic.h"

namespace Ui {
class settings;
}


class Global_Settings : public QMainWindow
{
    Q_OBJECT
public:
    explicit Global_Settings(QWidget *parent = nullptr);
    ~Global_Settings();
    void showroutine();
    void showmessage();
    void showdisplay();
    void showdTraffic();
private:
    Ui::settings *ui;
    QStackedWidget *stackedWidget_;
    display *display_;
    message *message_;
    routine *routine_;
    Traffic *Traffic_;
signals:
};

#endif // GLOBAL_SETTINGS_H
