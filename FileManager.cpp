//
// Created by emanuele on 18/09/16.
//

#include <iostream>
#include "FileManager.h"

FileManager::FileManager() : fileUploaded(0) {

}

FileManager::~FileManager() {


}

void FileManager::uploadFiles(int numFiles) {
    for (int i = 0; i < numFiles; i++) {
        fileUploaded++;
        int percentage = (fileUploaded * 100) / numFiles;
        notify(percentage);
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