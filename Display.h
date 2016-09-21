//
// Created by emanuele on 18/09/16.
//

#ifndef PRIMO_DISPLAY_H
#define PRIMO_DISPLAY_H

class Display {
public:
    virtual ~Display() {}

    virtual void draw()=0;
};

#endif //PRIMO_DISPLAY_H
