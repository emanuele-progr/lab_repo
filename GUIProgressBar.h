//
// Created by emanuele on 27/09/16.
//

#ifndef PROGRESSBAR_GUIPROGRESSBAR_H
#define PROGRESSBAR_GUIPROGRESSBAR_H

#include <list>
#include "GUIBar.h"
#include "FileManager.h"
#include "ResourceFile.h"

class GUIProgressBar : public GUIBar, public Display {
public:
    virtual ~GUIProgressBar();

    GUIProgressBar(FileManager *s);

    virtual void draw() override;


private:
    WINDOW *progressbar;
};


#endif //PROGRESSBAR_GUIPROGRESSBAR_H
