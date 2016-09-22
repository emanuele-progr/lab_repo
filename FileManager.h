//
// Created by emanuele on 18/09/16.
//

#ifndef PRIMO_FILEMANAGER_H
#define PRIMO_FILEMANAGER_H


#include "Subject.h"
#include <list>
#include <string>


class FileManager : public Subject {
public:
    FileManager();

    virtual ~FileManager();

    void loadFiles(int numFiles);

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    virtual void notify(int percentage) override;

    int getFileLoaded() const;

    const std::list<Observer *> &getObservers() const;

private:

    std::list<Observer *> observers;
    int fileLoaded;
};


#endif //PRIMO_FILEMANAGER_H
