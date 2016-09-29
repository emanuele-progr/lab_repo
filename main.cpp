
#include "FileManager.h"
#include "GUIProgressBar.h"

void Loading(FileManager *ptr) {
    ResourceFile *files[10];
    files[0] = new ResourceFile("Resource_001", 5);
    files[1] = new ResourceFile("Resource_009", 8);
    files[2] = new ResourceFile("Resource_021", 3);
    files[3] = new ResourceFile("Resource_054", 2);
    files[4] = new ResourceFile("Resource_086", 1);
    files[5] = new ResourceFile("Resource_091", 6);
    files[6] = new ResourceFile("Resource_112", 1);
    files[7] = new ResourceFile("Resource_161", 1);
    files[8] = new ResourceFile("Resource_172", 4);
    files[9] = new ResourceFile("Resource_179", 7);
    files[10] = new ResourceFile("Resource_199", 2);
    ptr->storeFiles(files[0]);
    ptr->storeFiles(files[1]);
    ptr->storeFiles(files[2]);
    ptr->storeFiles(files[3]);
    ptr->storeFiles(files[4]);
    ptr->storeFiles(files[5]);
    ptr->storeFiles(files[6]);
    ptr->storeFiles(files[7]);
    ptr->storeFiles(files[8]);
    ptr->storeFiles(files[9]);
    ptr->storeFiles(files[10]);
    ptr->loadFiles();
}

int main() {

    FileManager *ptr = new FileManager;
    GUIProgressBar bar(ptr);
    bar.attach();
    Loading(ptr);

    return 0;
}


