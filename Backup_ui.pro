QT       += core gui
QT       += uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    create.cpp \
    display.cpp \
    global_settings.cpp \
    main.cpp \
    mainwindow.cpp \
    message.cpp \
    routine.cpp \
    synchronize_logs.cpp \
    synchronize_tasks.cpp \
    tasks.cpp \
    traffic.cpp \
    ThreadPool.cpp \
    inotify.cpp \
    ClientSocket.cpp \
    File_send.cpp \
    Backup.cpp \
    workerthread.cpp


HEADERS += \
    create.h \
    display.h \
    global_settings.h \
    mainwindow.h \
    message.h \
    routine.h \
    synchronize_logs.h \
    synchronize_tasks.h \
    tasks.h \
    traffic.h \
    ThreadPool.h \
    inotify.h \
    ClientSocket.h \
    File.h \
    File_send.h \
    Backup.h \
    workerthread.h

FORMS += \
    Global_Settings.ui \
    Traffic.ui \
    create.ui \
    display.ui \
    mainwindow.ui \
    message.ui \
    routine.ui \
    synchronize_logs.ui \
    taskWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
