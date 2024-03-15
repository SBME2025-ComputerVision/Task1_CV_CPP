QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

CONFIG += link_pkgconfig
PKGCONFIG += opencv4


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Controllers/imagecontroller.cpp \
    Helpers/helpers.cpp \
    Models/filter.cpp \
    Models/fourier.cpp \
    Models/noise.cpp \
    Models/image.cpp \
    UI/filterswidget.cpp \
    UI/frequencywidget.cpp \
    UI/mainwindow.cpp \
    config.cpp \
    main.cpp

HEADERS += \
    Controllers/imagecontroller.h \
    Helpers/helpers.h \
    Models/filter.h \
    Models/fourier.h \
    Models/image.h \
    Models/noise.h \
    UI/filterswidget.h \
    UI/frequencywidget.h \
    UI/mainwindow.h \
    config.h \

FORMS += \
    UI/filterswidget.ui \
    UI/frequencywidget.ui \
    UI/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -LC:/tools/opencv/build/x64/vc14/lib/ -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/tools/opencv/build/x64/vc14/lib/ -lopencv_world451d


DISTFILES += \
    Gallery/baby with a ball.jpg \
    Gallery/bird.jpg \
    Gallery/cat.jpg \
    Gallery/cutie.jpg \
    Gallery/forest and mountain.jpg \
    Gallery/happy dog.jpg \
    Gallery/hiker 2.jpg \
    Gallery/palestine.jpg \
    Gallery/pyramids and a photographer.jpg \
    Gallery/whale.jpg \
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
