#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //设置主界面参数
    ui->setupUi(this);
    ui->toolBar->setStyleSheet("QToolBar { spacing: 30px; }");
    ui->toolBar->setMovable(false);
    this->setStyleSheet("QMainWindow::title { background-color: grey; }");

    // 创建并添加QStackedWidget
    stackedWidget_ = new QStackedWidget(this);
    setCentralWidget(stackedWidget_);

    //创建内容类
    Synchronize_logs_ = new Synchronize_logs(this);
    synchronize_tasks_ = new synchronize_tasks(this, Synchronize_logs_);
    Global_settings_ = new Global_Settings(this);


    // 将内容类添加到stackedWidget
    stackedWidget_->addWidget(synchronize_tasks_);
    stackedWidget_->addWidget(Synchronize_logs_);
    stackedWidget_->addWidget(Global_settings_);

    // 连接 QAction 的 triggered 信号到槽函数
    connect(ui->action, &QAction::triggered, this, &MainWindow::showContent1);
    connect(ui->action_2, &QAction::triggered, this, &MainWindow::showContent2);
    connect(ui->action_3, &QAction::triggered, this, &MainWindow::showContent3);

}

MainWindow::~MainWindow()
{
    delete synchronize_tasks_;
    delete Synchronize_logs_;
    delete Global_settings_;
    delete stackedWidget_;
    delete ui;
}
