#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
signals:
    void resultReady(const QString &result);

public slots:
    void doWork() {
        // 执行耗时的任务
        QString result = "Hello, World!";
        emit resultReady(result); // 发送任务结果
    }
};

#endif // WORKER_H
