//
// Created by emanuele on 22/09/16.
//

#include "gtest/gtest.h"
#include "../ResourceFile.h"
#include "../FileManager.h"


class FileManagerSuite : public ::testing::Test {

protected:
    virtual void TearDown() {
        delete file1, file2, file3;
    }

    virtual void SetUp() {
        file1 = new ResourceFile("Test1", 2);
        file2 = new ResourceFile("Test2", 6);
        file3 = new ResourceFile("Test3", -1);


    }

    ResourceFile *file1;
    ResourceFile *file2;
    ResourceFile *file3;
    FileManager f;
    FileManager m;
};


TEST_F(FileManagerSuite, FileManagerSuite_Store_Test) {
    ASSERT_TRUE(f.storeFiles(file1));
    ASSERT_EQ(1, f.getFiles().size());
    ASSERT_TRUE(f.storeFiles(file2));
    ASSERT_EQ(2, f.getFiles().size());
    ASSERT_FALSE(f.storeFiles(file3));
    ASSERT_EQ(2, f.getFiles().size());
}


TEST_F(FileManagerSuite, FileManagerSuite_LoadTest_Test) {
    f.storeFiles(file1);
    f.loadFiles();
    ASSERT_EQ(1, f.getFileLoaded());
    ASSERT_EQ(2, f.getBytesLoaded());
    m.storeFiles(file1);
    m.storeFiles(file2);
    m.loadFiles();
    ASSERT_EQ(2, m.getFileLoaded());
    ASSERT_EQ(8, m.getBytesLoaded());
}
