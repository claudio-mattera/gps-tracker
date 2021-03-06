cmake_minimum_required(VERSION 3.7.0)

project(gps-tracker LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt5Widgets)
find_package(Qt5Location)
find_package(Qt5QuickWidgets)
find_package(Qt5Charts)

add_executable(
    gps-tracker
    WIN32
    main.cpp
    MainWindow.cpp
    ProgressDialog.cpp
    GpxModel.cpp
    GpxItem.cpp
    PathController.cpp
    MapWidget.qrc
    ${version_file}
)

target_link_libraries(
    gps-tracker
    verdigris
    gpxlib
    Qt5::Widgets
    Qt5::QuickWidgets
    Qt5::Location
    Qt5::Charts
)

install(
    TARGETS gps-tracker
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
