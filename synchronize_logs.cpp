#include "synchronize_logs.h"
#include <QDebug>

Synchronize_logs::Synchronize_logs(QWidget *parent)
    : QWidget{parent},
    ui(new Ui::logs)
{
    ui->setupUi(this);
    treeWidget_ = new QTreeWidget(); // 这里的 parent 可以是窗口或其他控件
    treeWidget_->setColumnCount(4); // 设置列数
    treeWidget_->setHeaderLabels({"名称", "文件/文件夹", "时间", "事件"}); // 设置列名

    ui->verticalLayout->addWidget(treeWidget_);

}

void Synchronize_logs::addLogs(FileInformation fileInfo, QString time) //添加日志信息
{
    qDebug() << "进入日志处理，参数分别是： "<< time << fileInfo.filename;
    QString filename = QString::fromUtf8(fileInfo.filename); // 使用 UTF-8 编码

    QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget_);

    item->setText(0,filename);
    item->setText(1,"文件");
    item->setText(2,time);
    item->setText(3,"上传");
    qDebug() << "创建日志成功 ";

    qDebug() << "创建日志失败 ";
}
Synchronize_logs::~Synchronize_logs()
{
    delete ui;
}
