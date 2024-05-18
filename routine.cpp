#include "routine.h"

routine::routine(QWidget *parent)
    : QWidget{parent},
    ui(new Ui::routine)
{
    ui->setupUi(this);
}
routine::~routine()
{
    delete ui;
}
