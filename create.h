#ifndef CREATE_H
#define CREATE_H

#include <QWidget>
#include <QDialog>
#include <QUiLoader>
#include <QFile>
#include <QVBoxLayout>
#include <fstream>
#include <iostream>
#include "ui_create.h"
#include <functional>
#include <string>
#include <QString>
namespace Ui {
class create;
}

class Create : public QDialog
{
    Q_OBJECT
public:
    explicit Create(QWidget *parent = nullptr);
    ~Create();
    void Close();

    void settask_itemscallback(std::function<void(const QString &, const QString &,const QString &)> fn); // 设置同步任务事件回调。
private:
    Ui::create *ui_;

    // 处理同步任务创建事件， 在synchronize_task中回调。
    std::function<void(const QString &, const QString &,const QString &)> task_itemscallback_;
signals:
};

#endif // CREATE_H
