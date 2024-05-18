#include "message.h"

message::message(QWidget *parent)
    : QWidget{parent},
    ui(new Ui::message)
{
    ui->setupUi(this);
}

message::~message()
{
    delete ui;
}
