#include "../Subject/FileP.h"
#include "gtest/gtest.h"

//
// Created by pbone on 18/12/2023.
//
TEST(FileP,Constructor) {
    FileP  fi("testimg.png","c:\\users\\pietro");
    ASSERT_EQ(fi.getName(), "testimg.png");
    ASSERT_EQ(fi.getPath(), "c:\\users\\pietro");
}