#include "traffic.h"

Traffic::Traffic(QWidget *parent)
    : QWidget{parent},
    ui(new Ui::Traffic)
{
    ui->setupUi(this);
}

Traffic::~Traffic()
{
    delete ui;
}
