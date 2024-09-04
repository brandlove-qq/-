TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        route_sssp.cpp

HEADERS += \
    common.h \
    directgraph.h \
    loadbalance.h \
    route_sssp.h
