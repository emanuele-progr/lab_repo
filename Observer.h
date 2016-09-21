//
// Created by emanuele on 18/09/16.
//

#ifndef PRIMO_OBSERVER_H
#define PRIMO_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}

    virtual void update(int up)=0;

    virtual void attach()=0;

    virtual void detach()=0;

};

#endif //PRIMO_OBSERVER_H
