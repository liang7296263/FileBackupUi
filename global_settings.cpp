#include "global_settings.h"

Global_Settings::Global_Settings(QWidget *parent)
    : QMainWindow{parent},
    ui(new Ui::settings)
{
    ui->setupUi(this);

    // 创建并添加QStackedWidget
    stackedWidget_ = new QStackedWidget(this);
    setCentralWidget(stackedWidget_);

    //创建内容类
    routine_ = new routine(this);
    message_ = new message(this);
    display_ = new display(this);
    Traffic_ = new Traffic(this);

    // 将内容类添加到stackedWidget
    stackedWidget_->addWidget(routine_);
    stackedWidget_->addWidget(message_);
    stackedWidget_->addWidget(display_);
    stackedWidget_->addWidget(Traffic_);

    // 连接 QAction 的 triggered 信号到槽函数
    connect(ui->routine, &QAction::triggered, this, &Global_Settings::showroutine);
    connect(ui->message, &QAction::triggered, this, &Global_Settings::showmessage);
    connect(ui->display, &QAction::triggered, this, &Global_Settings::showdisplay);
    connect(ui->Traffic, &QAction::triggered, this, &Global_Settings::showdTraffic);
}

void Global_Settings::showroutine()
{
    stackedWidget_->setCurrentWidget(routine_);
}
void Global_Settings::showmessage()
{
    stackedWidget_->setCurrentWidget(message_);
}
void Global_Settings::showdisplay()
{
    stackedWidget_->setCurrentWidget(display_);
}
void Global_Settings::showdTraffic()
{
    stackedWidget_->setCurrentWidget(Traffic_);
}

Global_Settings::~Global_Settings()
{

    delete stackedWidget_;
    delete ui;
}
