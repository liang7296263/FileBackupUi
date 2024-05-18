#include "create.h"
#include <QDebug>


Create::Create(QWidget *parent)
    : QDialog{parent},
    ui_(new Ui::create)
{
    ui_->setupUi(this);

    //创建退出按键信号曹链接
    connect(ui_->quit, &QPushButton::clicked, this, &Create::Close);
    //创建创建按键信号槽链接
    connect(ui_->create_n, &QPushButton::clicked, [this](){
        QString ip = ui_->ip->text();
        QString port = ui_->port->text();
        QString path = ui_->path->text();
        std::ofstream fin(ui_->path->text().toStdString() + "/c.txt"); // 创建文件流

        //写入ip
        if (fin.is_open()) {
            fin << ui_->ip->text().toStdString() << std::endl;
            fin.close();
        } else {
            qDebug() << "IP 写入失败!";
            this->close();
        }

        // 重新打开文件并写入第二行数据
        fin.open(ui_->path->text().toStdString() + "/c.txt", std::ios::app);
        if (fin.is_open()) {
            fin << ui_->port->text().toStdString() << std::endl;
            fin.close();
        } else {
            qDebug() << "端口写入失败!";
            this->close();
        }

        // 重新打开文件并写入第三行数据
        fin.open(ui_->path->text().toStdString() + "/c.txt", std::ios::app);
        if (fin.is_open()) {
            fin << ui_->path->text().toStdString() << std::endl;
            fin.close();
        } else {
            qDebug() << "监控路径写入失败!";
            return 1;
            this->close();
        }
        task_itemscallback_(ip, port, path);
        this->Close();
    });

}


void Create::Close()
{
    this->close();
    this->deleteLater();
}
// /home/liang/code/Backup_ui/Backup_ui

void Create::settask_itemscallback(std::function<void(const QString &, const QString &,const QString &)> fn)
{
    task_itemscallback_ = fn;
}    // 设置同步任务事件回调。

Create::~Create()
{
    delete ui_;
}

