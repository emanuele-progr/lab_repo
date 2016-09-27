//
// Created by emanuele on 27/09/16.
//

#ifndef PROGRESSBAR_GUIPROGRESSBAR_H
#define PROGRESSBAR_GUIPROGRESSBAR_H

#include "GUIBar.h"
#include "FileManager.h"

class GUIProgressBar : public GUIBar {
public:
    virtual ~GUIProgressBar();

    GUIProgressBar(FileManager *f);

    virtual void draw() override;

    virtual void attach() override;

    virtual void detach() override;

private:
    WINDOW *progressbar;
    FileManager *subject;
};


#endif //PROGRESSBAR_GUIPROGRESSBAR_H