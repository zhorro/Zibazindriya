# Add more folders to ship with the application, here
folder_01.source = qml
folder_01.target = .
DEPLOYMENTFOLDERS += folder_01

# Add more folders to ship with the application, here
folder_02.source = opml
folder_02.target = .
DEPLOYMENTFOLDERS += folder_02

# Add more folders to ship with the application, here
folder_03.source = Images
folder_03.target = .
DEPLOYMENTFOLDERS += folder_03

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE3C43CA4

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
CONFIG += qdeclarative-boostable

# Add dependency to Symbian components
# CONFIG += qt-components
QT       += core gui xml sql network

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    RSS/folderviewer.cpp \
    podcastsdb.cpp \
    opmlimport.cpp \
    RSS/rssParser.cpp \
    RSS/episode.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \ 
    Zibazindriya.qmlproject \
    Ziba.vcxproj.filters \
    Ziba.vcxproj \
    Ziba.sln \
    qml/TestPageWithLists.qml

HEADERS += \ 
    RSS/folderviewer.h \
    podcastsdb.h \
    opmlimport.h \
    RSS/rssParser.h \
    RSS/episode.h
