//
// Created by emanuele on 18/09/16.
//

#ifndef PRIMO_GUIBAR_H
#define PRIMO_GUIBAR_H

#include <ncurses.h>
#include "Observer.h"
#include "Display.h"
#include "FileManager.h"


class GUIBar : public Observer, public Display {
public:

    GUIBar();

    virtual ~GUIBar();

    virtual void draw() override;

    virtual void update(int up) override;

    virtual void attach() override;

    virtual void detach() override;

    int getUpl() const;

    void setUpl(int upl);

private:
    int upl;
};


#endif //PRIMO_GUIBAR_H
