//
// Created by emanuele on 29/09/16.
//

#include "../GUIBar.h"
#include "gtest/gtest.h"

TEST(GUIBarTest, Construc__Test) {
    GUIBar bar;
    ASSERT_EQ(0, bar.getBUpl());
    ASSERT_EQ(0, bar.getFUpl());
    ASSERT_EQ("NoFile", bar.getCurrentName());
}

TEST(GUIBarTest, GUIBarTest_Update_Test) {
    GUIBar bar;
    bar.update(1, 3, "Test1");
    ASSERT_EQ(1, bar.getBUpl());
    ASSERT_EQ(3, bar.getFUpl());
    ASSERT_EQ("Test1", bar.getCurrentName());
    bar.update(-2, 1, "Test2");
    ASSERT_EQ(1, bar.getBUpl());
    ASSERT_EQ(3, bar.getFUpl());
    ASSERT_EQ("Test1", bar.getCurrentName());
    bar.update(3, -5, "Test3");
    ASSERT_EQ(1, bar.getBUpl());
    ASSERT_EQ(3, bar.getFUpl());
    ASSERT_EQ("Test1", bar.getCurrentName());

}