//
// Created by emanuele on 18/09/16.
//

#include <iostream>
#include "GUIBar.h"
#include "ListException.h"


GUIBar::GUIBar(FileManager *f) : subject(f), bUpl(0), fUpl(0), currentName("NoFile") {
}

GUIBar::~GUIBar() {
    detach();
}


void GUIBar::draw() {
    //uso la classe derivata per il display...

}

void GUIBar::update(int bUp, int fUp,
                    std::string fileName) throw(NegativeOrNullBytesException, NegativeOrNullFilesException) {
    if (bUp <= 0) {
        throw NegativeOrNullBytesException(
                "Errore impossibile aggiornare bytesUploaded : quantità di bytes nulla o negativa");
    }
    if (fUp <= 0) {
        throw NegativeOrNullFilesException(
                "Errore impossibile aggiornare fileUploaded : quantità files nulla o negativa");
    }
    bUpl = bUp;
    fUpl = fUp;
    currentName = fileName;
    draw();
}

void GUIBar::attach() {
    subject->subscribe(this);
}

void GUIBar::detach() {
    subject->unsubscribe(this);
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






