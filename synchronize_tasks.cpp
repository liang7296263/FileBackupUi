#include "synchronize_tasks.h"
#include <QDebug>

synchronize_tasks::synchronize_tasks(QWidget *parent, Synchronize_logs * logsPtr)
    : QWidget{parent}, logsPtr_(logsPtr)

{
    selectedWidget_.clear();
    NewTask = new QPushButton("创建");
    Pause = new QPushButton("暂停");
    Delete = new QPushButton("删除");
    EditLink = new QPushButton("编辑链接");
    // 创建水平布局管理器
    topLayout_ = new QHBoxLayout();
    // 将四个按钮添加到水平布局中
    topLayout_->addWidget(NewTask);
    topLayout_->addWidget(Pause);
    topLayout_->addWidget(Delete);
    topLayout_->addWidget(EditLink);

    topLayout_->setSpacing(30);

    // 创建垂直布局
    layout_ = new QVBoxLayout();
    // 将按钮添加到布局中
    layout_->addLayout(topLayout_);

    // 设置垂直布局的对齐方式为顶部对齐
    layout_->setAlignment(Qt::AlignTop);

    this->setLayout(layout_);


    connect(NewTask, &QPushButton::clicked, this, &synchronize_tasks::showNewTask);
    connect(Delete, &QPushButton::clicked, this, &synchronize_tasks::deleteSelectedWidget);

    //updateDeleteButtonState();

    //检查和加载配置文件
    Configuration_loading();

}

void synchronize_tasks::showNewTask()
{
    create_ = new Create(this);
    create_->settask_itemscallback(std::bind(&synchronize_tasks::crearTask_items, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    create_->exec();
}

void synchronize_tasks::crearTask_items(const QString &ip, const QString &port,const QString &path)   // 创建监控任务列表
{

    qDebug() << "执行创建任务";
    tasks *items = new tasks();
    items->setipText(ip);
    items->setportText(port);
    items->setpathText(path);
    items->setlogsPtr(logsPtr_);
    layout_->addWidget(items);
    connect(items, &tasks::widgetSelected, this, &synchronize_tasks::widgetSelected);
    Vtasks_.append(items);

    //修改任务数量配置文件
    QSettings settings(configFilePath_, QSettings::IniFormat);
    int Tasks = settings.value("tasks/Number").toInt(); //提取任务数量
    Tasks += 1;
    // 设置新的用户名值
    settings.setValue("tasks/Number", Tasks);

    //修改任务信息配置文件
    QSettings settingtasks(configPath_, QSettings::IniFormat);
    QString str = "task" + QString::number(Tasks);

    settingtasks.setValue(str + "/ip", ip);
    settingtasks.setValue(str + "/port", port);
    settingtasks.setValue(str + "/path", path);
}


void synchronize_tasks::widgetSelected(tasks *task) {
    // 更新选中的控件
    qDebug() << "更新选中的控件";
    selectedWidget_.clear();
    selectedWidget_.append(task);
    //updateDeleteButtonState();
}

void synchronize_tasks::deleteSelectedWidget() {
    // 删除选中的控件
    qDebug() << "删除选中的控件";
    if (!selectedWidget_.empty()) {
        selectedWidget_[0]->deleteLater();
        selectedWidget_.clear();
    }else {
        qDebug() << "selectedWidget为空";
    }
}
void synchronize_tasks::deleteVtasks_()
{
    if(!Vtasks_.isEmpty())
    {
        for(auto &c : Vtasks_)
        {
            delete c;
        }
    }else {
        return;
    }
}

void synchronize_tasks::setlogsPtr(Synchronize_logs * logsPtr)
{
    logsPtr_ = logsPtr;
}

void synchronize_tasks::Configuration_loading()//配置文件检查和生成
{
    QFile configFile(configFilePath_);
    if (!configFile.exists()) {
        qDebug() << "Config file doesn't exist. Generating default config...";

        // 生成默认任务数量配置文件
        QSettings settings(configFilePath_, QSettings::IniFormat);
        settings.setValue("tasks/Number", 0);
        qDebug() << "Default config generated at:" << configFilePath_;

        //生成默认任务信息配置文件
        QSettings settingtasks(configPath_, QSettings::IniFormat);
        settingtasks.setValue("task1/ip", "");
    }
    else
    {

        //读取任务数量，通过任务数量，创建任务
        QSettings settings(configFilePath_, QSettings::IniFormat);
        int Tasks = settings.value("tasks/Number").toInt(); //提取任务数量

        //如果任务数量不等于0
        if(Tasks != 0)
        {
            //读取任务配置文件
            QSettings settingtasks(configPath_, QSettings::IniFormat);
            //通过for循环，依次根据配置信息创建任务
            for(int ii = 1; ii < (Tasks + 1); ++ii)
            {
                QString str = "task";
                str.append(QString::number(ii));
                //读取配置信息
                QString ip = settingtasks.value(str + "/" + "ip").toString();
                QString port = settingtasks.value(str + "/" + "port").toString();
                QString path = settingtasks.value(str + "/" + "path").toString();

                // 根据配置创建tasks
                qDebug() << "执行创建任务";
                tasks *items = new tasks();
                items->setipText(ip);
                items->setportText(port);
                items->setpathText(path);
                items->setlogsPtr(logsPtr_);
                layout_->addWidget(items);
                connect(items, &tasks::widgetSelected, this, &synchronize_tasks::widgetSelected);
                Vtasks_.append(items);
            }
        }
    }
}

synchronize_tasks::~synchronize_tasks()
{
    //delete NewTask;
    //delete Pause;
    //delete Delete;
    //delete EditLink;
    //delete layout_;
    //delete topLayout_;
    //delete create_;
    //delete selectedWidget;
    //deleteVtasks_()
}

