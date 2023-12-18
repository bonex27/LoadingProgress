//
// Created by pbone on 06/06/2023.
//
#include "gtest/gtest.h"
#include "../Subject/FileLoader.h"

#include <bemapiset.h>


TEST(FileLoader, addFile) {
    FileLoader db;

    ASSERT_TRUE(db.addFile({"img.png","c:\\user\\immagini"}));
    ASSERT_FALSE(db.addFile({"img.png","c:\\user\\immagini"})); // Add existing file
    ASSERT_TRUE(db.addFile({"img1.png","c:\\user\\immagini"})); // Add existing file

}

TEST(FileLoader, removeFile) {
    FileLoader db;

    ASSERT_TRUE(db.addFile({"img.png","c:\\user\\immagini"}));
    ASSERT_TRUE(db.addFile({"img1.png","c:\\user\\immagini"})); // Add existing file
    ASSERT_FALSE(db.removeFile("img2.png"));
    ASSERT_TRUE(db.removeFile("img1.png"));
}
TEST(FileLoader, getLoadedFile) {
    FileLoader db;

    ASSERT_TRUE(db.addFile({"img.png","c:\\user\\immagini"}));
    ASSERT_TRUE(db.addFile({"img1.png","c:\\user\\immagini"})); // Add existing file
    ASSERT_EQ(db.getLoadedFile(),0);
    db.loadFile();
    ASSERT_EQ(db.getLoadedFile(),2);
}

