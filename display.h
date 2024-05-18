#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include "ui_display.h"

namespace Ui {
class display;
}

class display : public QWidget
{
    Q_OBJECT
public:
    explicit display(QWidget *parent = nullptr);
    ~display();
private:
    Ui::display *ui;
signals:
};

#endif // DISPLAY_H
