
#include "FileManager.h"
#include "GUIProgressBar.h"


int main() {

    FileManager *ptr = new FileManager;
    GUIProgressBar bar(ptr);
    bar.attach();
    ptr->loadFiles(107);

    return 0;
}
