include(C:/yaml-cpp/includeyamlcpp.pri)

INCLUDEPATH += \
    $$PWD/include

win32-g++:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lprotocol-serializer
else:win32-g++:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lprotocol-serializerd
else:msvc:win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lprotocol-serializer
else:msvc:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lprotocol-serializerd
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lprotocol-serializer
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lprotocol-serializerd

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libprotocol-serializer.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libprotocol-serializer.a
else:msvc:win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/protocol-serializer.lib
else:msvc:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/protocol-serializer.lib
