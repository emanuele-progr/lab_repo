//
// Created by emanuele on 18/09/16.
//

#include <iostream>
#include "FileManager.h"

FileManager::FileManager() : fileLoaded(0), bytesLoaded(0) {

}

FileManager::~FileManager() {

}

void FileManager::loadFiles() {
    int count = 0;
    int totBytes = 0;
    for (auto itr = std::begin(files); itr != std::end(files); itr++) {
        count++;
        totBytes += (*itr)->getBytes();
    }
    for (auto itr = std::begin(files); itr != std::end(files); itr++) {
        bytesLoaded += (*itr)->getBytes();
        fileLoaded++;
        std::string name = (*itr)->getFileName();
        int bytesPercentage = (bytesLoaded * 100) / totBytes;
        int filesPercentage = (fileLoaded * 100) / count;
        notify(bytesPercentage, filesPercentage, name);
    }
}

void FileManager::subscribe(Observer *o) {
    observers.push_back(o);

}

void FileManager::unsubscribe(Observer *o) {
    observers.remove(o);
}

void FileManager::notify(int bytesPercentage, int filesPercentage, std::string fileName) {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update(bytesPercentage, filesPercentage, fileName);
    }
}

int FileManager::getFileLoaded() const {
    return fileLoaded;
}

const std::list<Observer *> &FileManager::getObservers() const {
    return observers;
}

bool FileManager::storeFiles(ResourceFile *f) {
    if (f->getBytes() <= 0) {
        std::cout << "Errore nel numero di bytes nel file" << std::endl;
        return false;
    }
    files.push_back(f);
    return true;

}

int FileManager::getBytesLoaded() const {
    return bytesLoaded;
}

const std::list<ResourceFile *> &FileManager::getFiles() const {
    return files;
}
