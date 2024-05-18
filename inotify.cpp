#include "inotify.h"
#include <QDebug>


inotify::inotify(const std::string &path) : path_(path)
{
    inotifyfd_  = inotify_init();
    setNonBlocking(inotifyfd_);
}

inotify::~inotify()
{
    ::close(inotifyfd_);
}

int inotify::inotifyfd()  // 返回inotify 实例的文件描述符
{
    return inotifyfd_;
}
/*inotify_event inotify::inotifyev() // 返回事件信息结构体
{
    return inotifyev_;
}*/

bool inotify::add_watch()
{
    int wd = inotify_add_watch(inotifyfd_, path_.c_str(), IN_CLOSE_WRITE | IN_DELETE);
    if (wd < 0)
    {
        std::cerr << "Error adding watch to directory" << std::endl;
        close(inotifyfd_);
        return false;
    }
    qDebug() << "加入监控任务";
    return true;
}

int inotify::setNonBlocking(int fd)  //设置文件描述符为非阻塞模式
{
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        return -1;
    }
    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        return -1;
    }
    return 0;
}
bool inotify::Star() // 开启监控
{
    char buffer[BUF_LEN];
    int num_bytes = read(inotifyfd_, buffer, BUF_LEN);
    if(num_bytes == -1)
        return false;
    else
    {
        for (int i = 0; i < num_bytes;)
        {
            struct inotify_event *event = (struct inotify_event *)&buffer[i];
            if (event->len)
            {
                if (event->mask & IN_CLOSE_WRITE)
                {
                    std::cout << "File modify: " << event->name << std::endl;
                    std::string filename = event->name;
                    FileModifycallback_(filename);
                }
                else if (event->mask & IN_DELETE)
                {
                    std::cout << "File deleted: " << event->name << std::endl;
                }
            }
            i += EVENT_SIZE + event->len;
        }
    return true;
    }

    /*if (num_bytes == -1) {
        // 如果没有数据可读，判断是否是暂时性的阻塞
        if (errno == EAGAIN || errno == EWOULDBLOCK)
        {
            //qDebug() << "No data available right now";
            return true;
        } else
        {
            qDebug() << "Error reading from inotify";
            return false;
        }
    } else if (num_bytes == 0)
    {
        qDebug() << "End of file reached";
        return false;
    } else
    {
        // 处理读取到的数据
        for (ssize_t i = 0; i < num_bytes;) {
            struct inotify_event *event = reinterpret_cast<struct inotify_event *>(&buffer[i]);
            if (event->len)
            {
                if (event->mask & IN_CLOSE_WRITE)
                {
                    qDebug() << "inotify的event->name是： " << event->name;
                    std::string filename;
                    filename = event->name;
                    qDebug() << "inotify的filename是： " << filename;
                    FileModifycallback_(filename);
                } else if (event->mask & IN_DELETE)
                {
                    std::cout << "File deleted: " << event->name << std::endl;
                }
            }
            i += EVENT_SIZE + event->len;
        }
        return true;
    }*/
}

void inotify::setFileCreatedcallback(std::function<void(std::string &)> fn) // 设置文件创建事件回调。
{
    FileCreatedcallback_ = fn;
}
void inotify::setFileModifycallback(std::function<void(std::string &)> fn)  // 设置文件修改事件回调。
{
    FileModifycallback_ = fn;
}
void inotify::setFileDeletecallback(std::function<void(std::string &)> fn)  // 设置文件修改事件回调。
{
    FileDeletecallback_ = fn;
}
