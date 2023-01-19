QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = desktop-gallery
TEMPLATE = app

SOURCES += \
    AlbumWidget.cpp \
    AlbumsListWidget.cpp \
    GalleryWidget.cpp \
    PictureDelegate.cpp \
    PictureWidget.cpp \
    ThumbnailProxyModel.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AlbumWidget.h \
    AlbumsListWidget.h \
    GalleryWidget.h \
    MainWindow.h \
    PictureDelegate.h \
    PictureWidget.h \
    ThumbnailProxyModel.h

FORMS += \
    AlbumWidget.ui \
    AlbumsListWidget.ui \
    GalleryWidget.ui \
    MainWindow.ui \
    PictureWidget.ui

# libs
unix: LIBS += -L$$OUT_PWD/../gallery-core/ -lgallery-core

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/../gallery-core
DEPENDPATH += $$PWD/../gallery-core

RESOURCES += \
    resource.qrc
