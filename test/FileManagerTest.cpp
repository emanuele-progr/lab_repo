//
// Created by emanuele on 22/09/16.
//

#include "gtest/gtest.h"
#include "../FileManager.h"
#include "../GUIBar.h"
#include "../GUIProgressBar.h"

TEST(FileManagerTest, DefaultConstructor) {
    FileManager f;
    ASSERT_EQ(0, f.getFileLoaded());
    ASSERT_EQ(0, f.getObservers().size());
}

TEST(FileManagerTest, TestLoadFiles) {
    FileManager f;
    f.loadFiles(0);
    ASSERT_EQ(0, f.getFileLoaded());
    f.loadFiles(-5);
    ASSERT_EQ(0, f.getFileLoaded());
    f.loadFiles(12);
    ASSERT_EQ(12, f.getFileLoaded());
}

TEST(FileManagerTest, TestSubscribe) {
    FileManager f;
    GUIProgressBar *ptr;
    f.subscribe(ptr);
    ASSERT_EQ(1, f.getObservers().size());
    f.unsubscribe(ptr);
    ASSERT_EQ(0, f.getObservers().size());
}