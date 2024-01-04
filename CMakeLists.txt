cmake_minimum_required(VERSION 3.5)
project(LoadingProgress VERSION 1.0 LANGUAGES CXX)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Required if: 1) using macOS and 2) using Brew
if(APPLE})
    set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/6.4.3/lib/cmake/")
endif()


# Find the QtWidgets library
find_package(QT NAMES Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        Observer/MainWindow/mainwindow.cpp
        Observer/MainWindow/mainwindow.h
        Observer/MainWindow/mainwindow.ui
        Interfaces/Observer.h
        Interfaces/Subject.h
        Subject/FileLoader.cpp
        Subject/FileLoader.h
        Subject/File.h
)

add_executable(LoadingProgress main.cpp)
add_library(core ${PROJECT_SOURCES})
target_link_libraries(core Qt6::Widgets)
add_subdirectory(tests)

target_link_libraries(LoadingProgress core)

# Use the Widgets module from Qt 5.

