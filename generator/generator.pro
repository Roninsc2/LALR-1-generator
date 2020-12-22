QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        grammar.cpp \
        grammar_main.cpp \
        grammarlrone.cpp \
        grammarlrzero.cpp \
        grammarsymbol.cpp \
        lexer.cpp \
        main.cpp \
        parser.cpp \
        table_manager.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    grammar.h \
    grammar_main.h \
    grammarlrone.h \
    grammarlrzero.h \
    grammarsymbol.h \
    lex_pars_exeption.h \
    lexer.h \
    node.h \
    parser.h \
    table_manager.h \
    token.h \
    types.h