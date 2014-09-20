CONFIG += console
QT += widgets

TEMPLATE = app
CONFIG += no_include_pwd
CONFIG -= app_bundle
macx{
INCLUDEPATH += /usr/local/Cellar/boost/1.55.0_2/include
LIBS += -L/usr/local/Cellar/boost/1.55.0_2/lib
LIBS += -lboost_system-mt -lboost_filesystem-mt
}
unix{
LIBS += -L/usr/lib/x86_64-linux-gnu -lboost_system  -lboost_filesystem
}
install_it.path = %{buildDir}/resources/
install_it.files += %{sourceDir}/resources/*

INSTALLS += install_it
HEADERS += *.h
SOURCES += *.cpp

QMAKE_CXXFLAGS += -std=c++11

# Copies the given files to the destination directory
defineTest(copyToDestdir) {
    files = $$1

    for(FILE, files) {
        DDIR = $$OUT_PWD

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        !win32 {
            QMAKE_POST_LINK += cp -r '"'$$FILE'"' '"'$$DDIR'"' $$escape_expand(\\n\\t)
        }
        win32 {
            QMAKE_POST_LINK += xcopy '"'$$FILE'"' '"'$$DDIR'"' /e /y $$escape_expand(\\n\\t)
        }
    }

    export(QMAKE_POST_LINK)
}
!win32 {
    copyToDestdir($$files($$PWD/resources/*))
}
win32 {
    copyToDestdir($$PWD/resources)
}

