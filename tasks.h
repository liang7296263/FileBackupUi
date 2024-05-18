#ifndef TASKS_H
#define TASKS_H

#include <QWidget>
#include "ui_task_items.h"
#include <QString>
#include <string>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include "Backup.h"
#include <QProcess>
#include "workerthread.h"
#include "synchronize_logs.h"
#include "File.h"

class tasks : public QWidget
{
    Q_OBJECT
public:
    explicit tasks(QWidget *parent = nullptr);


    void setipText(const QString &ip);
    void setportText(const QString &port);
    void setpathText(const QString &path);

    const std::string ipText();
    const std::string portText();
    const std::string pathText();
    void setlogsPtr(Synchronize_logs * logsPtr);
private:
    QLabel *ipLabel_;
    QLineEdit * ipEdit_;
    QLabel *portLabel_;
    QLineEdit * portEdit_;
    QLabel *pathLabel_;
    QLineEdit * pathEdit_;

    Backup * backup_;
    QPushButton * start_;

    QHBoxLayout * ipAndportQh_;
    QHBoxLayout * pathQh_;

    QVBoxLayout * ipAndportAndpathVb_;

    QHBoxLayout *all_;

    QProcess *process_;
    WorkerThread *workerThread_;

    Synchronize_logs * logsPtr_;
private slots:
    void EnableBackup();
    void stopWorkerThread();
    void handleData(FileInformation fileInformation, QString time);
protected:
    void mousePressEvent(QMouseEvent *event) override {
        // 调用基类的事件处理函数
        QWidget::mousePressEvent(event);
        this->setStyleSheet("background-color: #f0f0f0;");
        // 发出选中信号
        emit widgetSelected(this);
    }
signals:
    void widgetSelected(tasks *task);
};

#endif // TASKS_H
