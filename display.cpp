#include "display.h"

display::display(QWidget *parent)
    : QWidget{parent},
    ui(new Ui::display)
{
    ui->setupUi(this);
}

display::~display()
{
    delete ui;
}
