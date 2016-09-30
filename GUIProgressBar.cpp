//
// Created by emanuele on 27/09/16.
//
#include <ncurses.h>
#include <string>
#include "GUIProgressBar.h"


GUIProgressBar::GUIProgressBar(FileManager *s) : subject(s) {
    //inizializzo la finestra per il caricamento...
    initscr();
    curs_set(0);
    noecho();
    progressbar = newwin(8, 112, 15, 20);

    setBUpl(0);
    setFUpl(0);
    setCurrentName("NoFile");

};

GUIProgressBar::~GUIProgressBar() {
    detach();
}

void GUIProgressBar::draw() {

    box(progressbar, ACS_VLINE, ACS_DIAMOND);
    mvwprintw(progressbar, 1, 3, "LOADING....");

    //simulo un ritardo nell'agg.percentuale dovuto al caricamento..

    wtimeout(progressbar, 500);
    wattron(progressbar, A_STANDOUT);
    if (GUIBar::getBUpl() < 101) {
        for (int i = 0; i < GUIBar::getBUpl(); i++) {
            mvwprintw(progressbar, 3, i + 6, "", 97);
            waddch(progressbar, 97 | A_ALTCHARSET);
        }

        wattroff(progressbar, A_STANDOUT);
        mvwprintw(progressbar, 5, 6, "Bytes percentage %d %%", GUIBar::getBUpl());
        mvwprintw(progressbar, 6, 6, "File percentage  %d %%", GUIBar::getFUpl());

        // display dei file..

        mvwprintw(progressbar, 5, 80, "Current File: %s", GUIBar::getCurrentName().c_str());
        wrefresh(progressbar);
        wgetch(progressbar);

    }
    refresh();

    if (GUIBar::getBUpl() == 100) {
        mvwprintw(progressbar, 6, 40, "LOADING COMPLETE!!!");
        mvprintw(25, 57, "Press any key to continue");
        wrefresh(progressbar);
        getch();
        endwin();
    }


}

void GUIProgressBar::attach() {
    subject->subscribe(this);

}

void GUIProgressBar::detach() {
    subject->unsubscribe(this);
}

