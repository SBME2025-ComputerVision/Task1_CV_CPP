QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -LC:/tools/opencv/build/x64/vc14/lib/ -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/tools/opencv/build/x64/vc14/lib/ -lopencv_world451d
INCLUDEPATH += C:/tools/opencv/build/include
DEPENDPATH += C:/tools/opencv/build/include


DISTFILES += \
    gitignore.txt \
    Icons/DropDownIcon.png \
    Icons/FilterIcon.png \
    Icons/Histogram.png \
    Icons/NoiseIcon.png \
    Icons/Sidebar.png \
    Icons/UploadIcon.png \
    Icons/close.png \
    Icons/contrast.png \
    Icons/convert_color_to_gray.png \
    Icons/edge_detection.png \
    Icons/sidebar-2-512.png \
