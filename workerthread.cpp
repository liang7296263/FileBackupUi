#include "workerthread.h"
#include <QDebug>

WorkerThread::WorkerThread(QObject *parent, const std::string &ip, const std::string &port, const std::string &path)
    : QThread(parent), ip_(ip), port_(port), path_(path),shouldStop_(false)
{
    backup_ = new Backup(nullptr, ip_, port_, path_);
    //connect(backup_, &Backup::resultReady, this, &WorkerThread::handleResult);
}

void WorkerThread::run()
{
    qDebug() << "backup_已经开启";
    backup_->Start();

     qDebug() << "线程已停止工作";
}

void WorkerThread::stopBackup()
{
    backup_->stopWork();
}

WorkerThread::~WorkerThread()
{
    delete backup_; // 释放备份对象的内存
}

 void WorkerThread::stop()
{
    backup_->Stop();
}

Backup* WorkerThread::getBackup() const
{
    return backup_;
}
