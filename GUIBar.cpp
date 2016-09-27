//
// Created by emanuele on 18/09/16.
//

#include "GUIBar.h"


GUIBar::GUIBar() {
    upl = 0;
}

GUIBar::~GUIBar() {
    detach();
}


void GUIBar::draw() {
    //uso la classe derivata per il display...

}

void GUIBar::update(int up) {
    upl = up;
    draw();
}

void GUIBar::attach() {}

void GUIBar::detach() {
}

int GUIBar::getUpl() const {
    return upl;
}

void GUIBar::setUpl(int upl) {
    GUIBar::upl = upl;
}


