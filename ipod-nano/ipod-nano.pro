# Add files and directories to ship with the application
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xE30C4A33

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the
# MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Display a console to display debug messages.
CONFIG += console

SOURCES += \
	src/main.cc \
	src/MainWindow.cc \
	src/IPodFrameWidget.cc \
	src/helpers.cc \
	src/apps/PeepholeApp.cc \
    src/apps/LayoutApp.cc \
	src/apps/PaintApp.cc \
	src/apps/MusicApp.cc \
	src/apps/ClockApp.cc \
	src/apps/GUIApp.cc \
	src/apps/MapApp.cc \
	src/apps/GestureApp.cc \
	src/apps/MarkingMenuApp.cc \
	src/apps/MultiTapApp.cc \
	src/apps/PickerApp.cc \
	src/apps/App.cc \
	src/widgets/TitleBarWidget.cc \
	src/widgets/TitleBarButtonWidget.cc \
	src/widgets/TextWidget.cc \
	src/widgets/PageIndicatorWidget.cc \
	src/widgets/ImageWidget.cc \
	src/widgets/ClickableWidget.cc \
	src/widgets/ButtonWidget.cc \
	src/widgets/ScalableButtonWidget.cc \
	src/widgets/SwitchButtonWidget.cc \
	src/widgets/SliderWidget.cc \
	src/widgets/BackgroundWidget.cc \
	src/widgets/FlickArea.cc \
	src/widgets/MarkingMenu.cc \
	src/widgets/PickerWidget.cc \
	src/widgets/OverlayWidget.cc \
	src/apps/MenuApp.cc \
	src/apps/InfoApp.cc
HEADERS += \
	src/MainWindow.h \
	src/IPodFrameWidget.h \
	src/helpers.h \
	src/apps/PeepholeApp.h \
    src/apps/LayoutApp.h \
	src/apps/PaintApp.h \
	src/apps/MusicApp.h \
	src/apps/ClockApp.h \
	src/apps/GUIApp.h \
	src/apps/MapApp.h \
	src/apps/GestureApp.h \
	src/apps/MarkingMenuApp.h \
	src/apps/MultiTapApp.h \
	src/apps/PickerApp.h \
	src/apps/App.h \
	src/widgets/TitleBarWidget.h \
	src/widgets/TitleBarButtonWidget.h \
	src/widgets/TextWidget.h \
	src/widgets/PageIndicatorWidget.h \
	src/widgets/ImageWidget.h \
	src/widgets/ClickableWidget.h \
	src/widgets/ButtonWidget.h \
	src/widgets/ScalableButtonWidget.h \
	src/widgets/SwitchButtonWidget.h \
	src/widgets/SliderWidget.h \
	src/widgets/BackgroundWidget.h \
	src/widgets/FlickArea.h \
	src/widgets/MarkingMenu.h \
	src/widgets/PickerWidget.h \
	src/widgets/OverlayWidget.h \
	src/apps/MenuApp.h \
	src/apps/InfoApp.h
FORMS +=

INCLUDEPATH += src src/apps src/widgets

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

RESOURCES += \
	resources.qrc




