
#include "FileManager.h"
#include "GUIBar.h"


int main() {

    FileManager *ptr = new FileManager;
    GUIBar *ptr2 = new GUIBar(ptr);
    ptr2->attach();
    ptr->uploadFiles(100);

    return 0;
}
