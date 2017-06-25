TEMPLATE = app
QT += core
QT += remoteobjects
QT -= gui

CONFIG += c++11

DESTDIR = $$ROOT_BUILD/bin
TARGET = {{module}}
CONFIG += console
CONFIG -= app_bundle

include(generated/generated.pri)

{% for interface in module.interfaces %}
HEADERS += {{interface|lower}}service.h
{% endfor %}

{% for interface in module.interfaces %}
SOURCES += {{interface|lower}}service.cpp
{% endfor %}
SOURCES += main.cpp
