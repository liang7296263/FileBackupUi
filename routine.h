#ifndef ROUTINE_H
#define ROUTINE_H

#include <QWidget>
#include <ui_routine.h>

namespace Ui {
class routine;
}

class routine : public QWidget
{
    Q_OBJECT
public:
    explicit routine(QWidget *parent = nullptr);
    ~routine();
private:
    Ui::routine *ui;
signals:
};

#endif // ROUTINE_H
