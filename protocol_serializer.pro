TEMPLATE = lib
CONFIG += console c++17 \
          no_testcase_installs
CONFIG -= app_bundle
CONFIG -= qt

QT += core \
    testlib

CONFIG(debug, debug|release) {
    TARGET = protocol-serializerd
}

CONFIG(release, debug|release) {
    TARGET = protocol-serializer}

CONFIG += staticlib

HEADERS += \
    include/analysis.h \
    include/control.h \
    include/currentctrl.h \
    include/currentprotocol.h \
    include/cursor.h \
    include/frequencyctrl.h \
    include/global_defines.h \
    include/iconst.h \
    include/ihold.h \
    include/infrepseq.h \
    include/iramp.h \
    include/irest.h \
    include/isin.h \
    include/isteptstep.h \
    include/naturalnumctrl.h \
    include/phase.h \
    include/protocols.h \
    include/repseq.h \
    include/repseqscaled.h \
    include/repseqwithsteps.h \
    include/timectrl.h \
    include/vconst.h \
    include/vhold.h \
    include/voltagectrl.h \
    include/voltageprotocol.h \
    include/vramp.h \
    include/vrest.h \
    include/vsin.h \
    include/vsteptstep.h

INCLUDEPATH += include
DEPENDPATH += include

target.path = $$PWD/
INSTALLS += target

include(C:/yaml-cpp/includeyamlcpp.pri)
