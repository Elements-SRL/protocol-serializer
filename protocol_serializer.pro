TEMPLATE = app
CONFIG += console c++17 \
          no_testcase_installs
CONFIG -= app_bundle
CONFIG -= qt

QT += core \
    testlib

SOURCES += \
    main.cpp

HEADERS += \
    analysis.h \
    control.h \
    currentctrl.h \
    currentprotocol.h \
    cursor.h \
    frequencyctrl.h \
    global_defines.h \
    iconst.h \
    ihold.h \
    infrepseq.h \
    iramp.h \
    irest.h \
    isin.h \
    isteptstep.h \
    naturalnumctrl.h \
    phase.h \
    protocols.h \
    repseq.h \
    repseqscaled.h \
    repseqwithsteps.h \
    timectrl.h \
    vconst.h \
    vhold.h \
    voltagectrl.h \
    voltageprotocol.h \
    vramp.h \
    vrest.h \
    vsin.h \
    vsteptstep.h

target.path = $$PWD/
INSTALLS += target

include(C:/yaml-cpp/includeyamlcpp.pri)
