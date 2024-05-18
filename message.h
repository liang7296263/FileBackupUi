#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include "ui_message.h"

namespace Ui {
class message;
}

class message : public QWidget
{
    Q_OBJECT
public:
    explicit message(QWidget *parent = nullptr);
    ~message();
private:
    Ui::message *ui;
signals:
};

#endif // MESSAGE_H
