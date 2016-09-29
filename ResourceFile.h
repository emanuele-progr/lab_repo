//
// Created by emanuele on 27/09/16.
//

#ifndef PROGRESSBAR_RESOURCEFILE_H
#define PROGRESSBAR_RESOURCEFILE_H

#include <string>

class ResourceFile {
public:
    ResourceFile(std::string name, int b);


    const std::string &getFileName() const;

    int getBytes() const;

private:
    std::string FileName;
    int bytes;
};


#endif //PROGRESSBAR_RESOURCEFILE_H
