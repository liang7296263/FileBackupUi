#ifndef SYNCHRONIZE_LOGS_H
#define SYNCHRONIZE_LOGS_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>
#include "ui_synchronize_logs.h"
#include "File.h"
#include <QTreeWidgetItem>
#include <QTreeWidget>


namespace Ui {
class logs;
}

class Synchronize_logs : public QWidget
{
    Q_OBJECT
public:
    explicit Synchronize_logs(QWidget *parent = nullptr);
    ~Synchronize_logs();
    void addLogs(FileInformation, QString time); //添加日志信息
private:
    Ui::logs *ui;

    QStandardItemModel *model_;
    QTreeWidget * treeWidget_;
signals:
};

#endif // SYNCHRONIZE_LOGS_H
