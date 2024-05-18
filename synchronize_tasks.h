#ifndef SYNCHRONIZE_TASKS_H
#define SYNCHRONIZE_TASKS_H

#include "ui_taskWindow.h"
#include <QMainWindow>
#include "create.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <fstream>
#include <QVector>
#include "tasks.h"
#include "synchronize_logs.h"
#include <QFile>
#include <QSettings>


class synchronize_tasks : public QWidget
{
    Q_OBJECT
public:
    explicit synchronize_tasks(QWidget *parent = nullptr, Synchronize_logs * logsPtr= nullptr);
    ~synchronize_tasks();
    void showNewTask();
    void crearTask_items(const QString &ip, const QString &port,const QString &path);   // 创建监控任务函数
    void showNewTask1();
    void deleteVtasks_();
    void setlogsPtr(Synchronize_logs * logsPtr);

    void Configuration_loading(); //配置文件检查和生成
private:
    QVector<tasks *> Vtasks_;
    QPushButton *NewTask;
    QPushButton *Pause;
    QPushButton *Delete;
    QPushButton *EditLink;

    QVBoxLayout *layout_;
    QHBoxLayout *topLayout_;

    Create * create_;
    QVector<tasks *> selectedWidget_;
    //QWidget *selectedWidget_ = nullptr;
    void updateDeleteButtonState();// 根据选中的控件是否为空来更新删除按钮的状态

    Synchronize_logs * logsPtr_;  //日志类地址

   const QString configFilePath_ = "/home/liang/tasksConfig.ini"; //任务数量配置文件地址
   const QString configPath_ = "/home/liang/Config.ini"; //任务数量配置文件地址
private slots:
    void widgetSelected(tasks *task);// 更新选中的控件
    void deleteSelectedWidget();// 删除选中的控件
signals:
};

#endif // SYNCHRONIZE_TASKS_H
