#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QObject>
#include <QThread>
#include "Backup.h"
class WorkerThread : public QThread
{
    Q_OBJECT
public:
    // 构造函数，接收三个参数
    WorkerThread(QObject *parent = nullptr, const std::string &ip = "",
                 const std::string &port = "", const std::string &path = "");
    ~WorkerThread();
    void run() override;

    // 用于停止Backup对象的工作
    void stopBackup();
    void stop();
    Backup* getBackup() const;
signals:
    void resultReady(bool b);

private slots:
    void handleResult(bool b) {
        emit resultReady(b);
    }
private:
    const std::string ip_;
    const std::string port_;
    const std::string path_;
    Backup * backup_; // 将Backup对象作为成员变量保存在WorkerThread中
    bool shouldStop_;
};

#endif // WORKERTHREAD_H
