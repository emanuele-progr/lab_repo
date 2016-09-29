//
// Created by emanuele on 27/09/16.
//

#include <iostream>
#include "ResourceFile.h"


ResourceFile::ResourceFile(std::string name, int b) : FileName(name), bytes(b) {
}

const std::string &ResourceFile::getFileName() const {
    return FileName;
}


int ResourceFile::getBytes() const {
    return bytes;
}


