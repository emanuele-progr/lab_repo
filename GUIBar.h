//
// Created by emanuele on 18/09/16.
//

#ifndef PRIMO_GUIBAR_H
#define PRIMO_GUIBAR_H

#include <string.h>
#include <ncurses.h>
#include "Observer.h"
#include "Display.h"
#include "FileManager.h"



class GUIBar : public Observer, public Display {
public:

    GUIBar();

    virtual ~GUIBar();

    virtual void draw() override;

    virtual void update(int bUp, int fUp, std::string fileName) override;

    virtual void attach() override;

    virtual void detach() override;

    int getBUpl() const;

    void setBUpl(int bUpl);

    int getFUpl() const;

    void setFUpl(int fUpl);

    void setCurrentName(const std::string &currentName);

    const std::string &getCurrentName() const;

private:
    int bUpl, fUpl;
    std::string currentName;
};


#endif //PRIMO_GUIBAR_H
