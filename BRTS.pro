QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../Desktop/jdbc-demo/BusAI/Routeengine.cpp \
    ../../Desktop/jdbc-demo/BusAI/mainwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../Desktop/jdbc-demo/BusAI/Routeengine.h \
    ../../Desktop/jdbc-demo/BusAI/mainwindow.h \
    mainwindow.h

FORMS += \
    ../../Desktop/jdbc-demo/BusAI/mainwindow.ui \
    mainwindow.ui \
    result.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../../Desktop/jdbc-demo/BusAI/main.exe
