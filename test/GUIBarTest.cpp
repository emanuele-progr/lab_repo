//
// Created by emanuele on 29/09/16.
//

#include "../GUIBar.h"
#include "gtest/gtest.h"

TEST(GUIBarTest, Construc__Test) {
    FileManager *f = new FileManager;
    GUIBar bar(f);
    ASSERT_EQ(0, bar.getBUpl());
    ASSERT_EQ(0, bar.getFUpl());
    ASSERT_EQ("NoFile", bar.getCurrentName());
}

TEST(GUIBarTest, GUIBarTest_Update_Test) {
    FileManager *f = new FileManager;
    GUIBar bar(f);
    bar.update(1, 3, "Test1");
    ASSERT_EQ(1, bar.getBUpl());
    ASSERT_EQ(3, bar.getFUpl());
    ASSERT_EQ("Test1", bar.getCurrentName());
    EXPECT_THROW(bar.update(-2, 1, "Test2"), NegativeOrNullBytesException);
    EXPECT_THROW(bar.update(1, 0, "Test3"), NegativeOrNullFilesException);

}

TEST(GUIBarTest, GUIBarTest_GUIBarAttachDetach_Test) {
    FileManager *f = new FileManager;
    GUIBar *bar = new GUIBar(f);
    bar->attach();
    ASSERT_EQ(1, f->getObservers().size());
    delete bar;
    ASSERT_EQ(0, f->getObservers().size());

}