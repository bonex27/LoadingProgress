cmake_minimum_required(VERSION 3.21)
project(LoadingProgress)

set(CMAKE_CXX_STANDARD 14)



# Required if: 1) using macOS and 2) using Brew
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/6.4.3/lib/cmake/")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# Find the QtWidgets library
find_package(QT NAMES Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# Tell CMake to create the helloworld executable
add_executable(LoadingProgress
        Observer/MainWindow/mainwindow.ui
        main.cpp timer.cpp timer.h
        Interfaces/Observer.cpp
        Interfaces/Observer.h Interfaces/Subject.cpp
        Interfaces/Subject.h
        Observer/MainWindow/mainwindow.cpp
        Observer/MainWindow/mainwindow.h
        )
#add_executable(qtHelloWorld WIN32 main.cpp)


# Use the Widgets module from Qt 5.
target_link_libraries(LoadingProgress Qt6::Widgets)
