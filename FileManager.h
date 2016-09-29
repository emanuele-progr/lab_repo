//
// Created by emanuele on 18/09/16.
//

#ifndef PRIMO_FILEMANAGER_H
#define PRIMO_FILEMANAGER_H


#include "Subject.h"
#include "ResourceFile.h"
#include <list>
#include <string>


class FileManager : public Subject {
public:
    FileManager();

    virtual ~FileManager();

    void loadFiles();

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    virtual void notify(int bytesPercentage, int filesPercentage, std::string fileName) override;

    int getFileLoaded() const;

    bool storeFiles(ResourceFile *f);

    const std::list<Observer *> &getObservers() const;

    int getBytesLoaded() const;

    const std::list<ResourceFile *> &getFiles() const;

private:

    std::list<Observer *> observers;
    int fileLoaded;
    int bytesLoaded;
    std::list<ResourceFile *> files;
};


#endif //PRIMO_FILEMANAGER_H
