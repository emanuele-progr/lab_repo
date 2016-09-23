//
// Created by emanuele on 18/09/16.
//

#include <iostream>
#include "FileManager.h"

FileManager::FileManager() : fileLoaded(0) {

}

FileManager::~FileManager() {


}

void FileManager::loadFiles(int numFiles) {
    if (numFiles < 0) {
        std::cout << "Error:Invalid file's number" << std::endl;
    } else {
        for (int i = 0; i < numFiles; i++) {
            fileLoaded++;

            //simulo file caricati con dimensione uguale..

            int percentage = (fileLoaded * 100) / numFiles;
            notify(percentage);
        }
    }
}

void FileManager::subscribe(Observer *o) {
    observers.push_back(o);

}

void FileManager::unsubscribe(Observer *o) {
    observers.remove(o);
}

void FileManager::notify(int percentage) {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update(percentage);
    }
}

int FileManager::getFileLoaded() const {
    return fileLoaded;
}

const std::list<Observer *> &FileManager::getObservers() const {
    return observers;
}
