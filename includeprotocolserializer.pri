include($$(YAML_CPP_PATH)/includeyamlcpp.pri)

INCLUDEPATH += \
    $$(PROTOCOL_SERIALIZER_PATH)include

win32-g++:CONFIG(release, debug|release): LIBS += -L$$(PROTOCOL_SERIALIZER_PATH)lib/release/ -lprotocol-serializer
else:win32-g++:CONFIG(debug, debug|release): LIBS += -L$$(PROTOCOL_SERIALIZER_PATH)lib/debug/ -lprotocol-serializerd
else:msvc:win32:CONFIG(release, debug|release): LIBS += -L$$(PROTOCOL_SERIALIZER_PATH)lib/release/ -lprotocol-serializer
else:msvc:win32:CONFIG(debug, debug|release): LIBS += -L$$(PROTOCOL_SERIALIZER_PATH)lib/debug/ -lprotocol-serializerd
else:unix:CONFIG(release, debug|release): LIBS += -L$$(PROTOCOL_SERIALIZER_PATH)lib/release/ -lprotocol-serializer
else:unix:CONFIG(debug, debug|release): LIBS += -L$$(PROTOCOL_SERIALIZER_PATH)lib/debug/ -lprotocol-serializerd

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$(PROTOCOL_SERIALIZER_PATH)lib/release/libprotocol-serializer.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$(PROTOCOL_SERIALIZER_PATH)lib/debug/libprotocol-serializerd.a
else:msvc:win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$(PROTOCOL_SERIALIZER_PATH)lib/release/protocol-serializer.lib
else:msvc:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$(PROTOCOL_SERIALIZER_PATH)lib/debug/protocol-serializerd.lib
