#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <QWidget>
#include "ui_Traffic.h"

namespace Ui {
class Traffic;
}

class Traffic : public QWidget
{
    Q_OBJECT
public:
    explicit Traffic(QWidget *parent = nullptr);
    ~Traffic();
private:
    Ui::Traffic *ui;
signals:
};

#endif // TRAFFIC_H
