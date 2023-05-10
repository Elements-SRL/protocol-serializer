DEFINES += YAML_CPP_STATIC_DEFINE

INCLUDEPATH += \
    $$PWD/include \
    $$PWD/include/yaml-cpp \
    $$PWD/include/yaml-cpp/node \
    $$PWD/include/yaml-cpp/node/detail \
    $$PWD/include/yaml-cpp/contrib

win32-g++:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../yaml-cpp/release/ -lyaml-cpp
else:win32-g++:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../yaml-cpp/debug/ -lyaml-cppd
else:msvc:win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../yaml-cpp/release/ -lyaml-cpp
else:msvc:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../yaml-cpp/debug/ -lyaml-cppd
else:unix:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../yaml-cpp/ -lyaml-cpp
else:unix:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../yaml-cpp/ -lyaml-cppd

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../yaml-cpp/release/libyaml-cpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../yaml-cpp/debug/libyaml-cppd.a
else:msvc:win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../yaml-cpp/release/yaml-cpp.lib
else:msvc:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../yaml-cpp/debug/yaml-cppd.lib
