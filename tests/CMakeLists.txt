cmake_minimum_required(VERSION 3.5)

add_subdirectory(.\\lib\\googletest)
set(gtest_SOURCE_DIR, .\\lib\\googletest\\)
include_directories(${gtest_SOURCE_DIR}\\include ${gtest_SOURCE_DIR})
# Find the QtWidgets library


set(TEST_SOURCE_FILES test.cpp FileLoader.cpp File.cpp
        ObserverTesting.cpp)
add_executable(LoadingProgress_Tests ${TEST_SOURCE_FILES})
target_link_libraries(LoadingProgress_Tests gtest gtest_main core)