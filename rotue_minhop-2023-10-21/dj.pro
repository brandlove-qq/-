TEMPLATE = app
CONFIG +=  c++11
CONFIG -= app_bundle
CONFIG += qt
CONFIG += resources_big
SOURCES += \
        main.cpp \
        route_minhop.cpp

HEADERS += \
    common.h \
    graph11.h \
    loadbalance.h \
    newfunction.h \
    route_minhop.h
