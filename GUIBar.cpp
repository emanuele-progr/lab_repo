//
// Created by emanuele on 18/09/16.
//

#include "GUIBar.h"


GUIBar::GUIBar() {
    bUpl = 0;
    fUpl = 0;
    currentName = "NoFile";
}

GUIBar::~GUIBar() {
    detach();
}


void GUIBar::draw() {
    //uso la classe derivata per il display...

}

void GUIBar::update(int bUp, int fUp, std::string fileName) {
    bUpl = bUp;
    fUpl = fUp;
    currentName = fileName;
    draw();
}

void GUIBar::attach() {}

void GUIBar::detach() {
}

int GUIBar::getBUpl() const {
    return bUpl;
}

void GUIBar::setBUpl(int bUpl) {
    GUIBar::bUpl = bUpl;
}

int GUIBar::getFUpl() const {
    return fUpl;
}

void GUIBar::setFUpl(int fUpl) {
    GUIBar::fUpl = fUpl;
}

void GUIBar::setCurrentName(const std::string &currentName) {
    GUIBar::currentName = currentName;
}

const std::string &GUIBar::getCurrentName() const {
    return currentName;
}






