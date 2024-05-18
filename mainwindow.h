#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "synchronize_tasks.h"
#include "synchronize_logs.h"
#include <QStackedWidget>
#include "global_settings.h"
#include "ui_mainwindow.h"
#include <memory>

using spsynchronize_tasks = std::shared_ptr<synchronize_tasks>;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    synchronize_tasks *synchronize_tasks_;
    Global_Settings * Global_settings_;
    Synchronize_logs *Synchronize_logs_;
    QStackedWidget *stackedWidget_;

private slots:
    void showContent1() {
        stackedWidget_->setCurrentWidget(synchronize_tasks_);
    }

    void showContent2() {
        stackedWidget_->setCurrentWidget(Synchronize_logs_);
    }

    void showContent3() {
        stackedWidget_->setCurrentWidget(Global_settings_);
    }
};
#endif // MAINWINDOW_H
