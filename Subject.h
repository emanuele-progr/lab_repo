//
// Created by emanuele on 18/09/16.
//

#ifndef PRIMO_SUBJECT_H
#define PRIMO_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer *o)=0;

    virtual void unsubscribe(Observer *o)=0;

    virtual void notify(int bytesPercentage, int filesPercentage, std::string fileName)=0;
};

#endif //PRIMO_SUBJECT_H
