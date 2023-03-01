TEMPLATE = app
CONFIG += console c++17 \
          no_testcase_installs
CONFIG -= app_bundle
CONFIG -= qt

QT += core \
      testlib

SOURCES += \
        main.cpp

DEFINES += YAML_CPP_STATIC_DEFINE

target.path = $$PWD/
INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lyaml-cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lyaml-cppd

INCLUDEPATH += $$PWD/yaml-cpp \
               $$PWD/yaml-cpp/contrib \
               $$PWD/yaml-cpp/node \
               $$PWD/yaml-cpp/node/detail

DEPENDPATH += $$PWD/yaml-cpp \
              $$PWD/yaml-cpp/contrib \
              $$PWD/yaml-cpp/node \
              $$PWD/yaml-cpp/node/detail

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./libyaml-cpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./libyaml-cppd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./yaml-cpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./yaml-cppd.lib

HEADERS += \
    cursor.h \
    phase.h \
    vconst.h \
    voltage_protocol.h \
    vramp.h \
    vsin.h \
    vstepstep.h
