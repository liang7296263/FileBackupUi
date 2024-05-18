#include "tasks.h"
#include <QDebug>

tasks::tasks(QWidget *parent)
    : QWidget{parent}, ipAndportQh_(new QHBoxLayout), pathQh_(new QHBoxLayout),
    ipLabel_(new QLabel()), ipEdit_(new QLineEdit()), portLabel_(new QLabel()), portEdit_(new QLineEdit()),
    pathLabel_(new QLabel()), pathEdit_(new QLineEdit()), start_(new QPushButton("开启同步")),
    ipAndportAndpathVb_(new QVBoxLayout), all_(new QHBoxLayout)
{

    start_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //创建ip和port的水平布局组合
    ipLabel_->setText("服务器ip地址");
    ipEdit_->setReadOnly(true);

    portLabel_->setText("服务器端口号");
    portEdit_->setReadOnly(true);

    ipAndportQh_->addWidget(ipLabel_);
    ipAndportQh_->addWidget(ipEdit_);
    ipAndportQh_->addWidget(portLabel_);
    ipAndportQh_->addWidget(portEdit_);

    //创建path水平组合
    pathLabel_->setText("监控文件夹地址");
    pathEdit_->setReadOnly(true);
    pathQh_->addWidget(pathLabel_);
    pathQh_->addWidget(pathEdit_);

    //创建属性栏垂直布局

    ipAndportAndpathVb_->addLayout(ipAndportQh_);
    ipAndportAndpathVb_->addLayout(pathQh_);

    //创建属性栏和按钮的总水平布局
    all_->addLayout(ipAndportAndpathVb_);
    all_->addWidget(start_);

    setLayout(all_);

    connect(start_, &QPushButton::clicked, this, &tasks::EnableBackup);
}

void tasks::EnableBackup()
{
    qDebug() << "进入开启同步功能";
    QString str1 = "开启同步";
    QString str2 = "暂停同步";

    //转换按钮文本,设置开启和暂停功能
    if(start_->text() == str1)
    {
        qDebug() << "开始同步";
        start_->setText(str2);
        qDebug() << ipText() << portText() << pathText();
        workerThread_ = new WorkerThread(this,ipText(), portText(), pathText());
        workerThread_->start();
        connect(workerThread_->getBackup(), &Backup::resultReady, this, &tasks::handleData);
        qDebug() << "同步开始";
    }
    else {
        start_->setText(str1);
        stopWorkerThread();

        qDebug() << "同步暂停";
    }

}

void tasks::setipText(const QString &ip)
{
    ipEdit_->setText(ip);
}
void tasks::setportText(const QString &port)
{
    portEdit_->setText(port);
}
void tasks::setpathText(const QString &path)
{
    pathEdit_->setText(path);
}

const std::string tasks::ipText()
{
    return ipEdit_->text().toStdString();
}
const std::string tasks::portText()
{
    return portEdit_->text().toStdString();
}
const std::string tasks::pathText()
{
    return pathEdit_->text().toStdString();
}

void tasks::stopWorkerThread()
{
    workerThread_->stop();

}

void tasks::setlogsPtr(Synchronize_logs * logsPtr)
{
    logsPtr_ = logsPtr;
}

void tasks::handleData(FileInformation fileInformation, QString time)
{
    logsPtr_->addLogs(fileInformation, time);
}
