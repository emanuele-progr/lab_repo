
#include "FileManager.h"
#include "GUIBar.h"


int main() {

    FileManager *ptr = new FileManager;
    GUIBar *ptr2 = new GUIBar(ptr);
    ptr2->attach();
    ptr->loadFiles(107);

    return 0;
}
