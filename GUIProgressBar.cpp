//
// Created by emanuele on 27/09/16.
//
#include <ncurses.h>
#include "GUIProgressBar.h"


GUIProgressBar::GUIProgressBar(FileManager *f) : subject(f) {
    //inizializzo la finestra per il caricamento...
    initscr();
    curs_set(0);
    noecho();
    progressbar = newwin(8, 112, 15, 20);

    setUpl(0);

};

GUIProgressBar::~GUIProgressBar() {
    detach();
}

void GUIProgressBar::draw() {

    box(progressbar, ACS_VLINE, ACS_DIAMOND);
    mvwprintw(progressbar, 1, 3, "LOADING....");

    //simulo un ritardo nell'agg.percentuale dovuto al caricamento..

    wtimeout(progressbar, 300);
    wattron(progressbar, A_STANDOUT);
    if (GUIBar::getUpl() < 101) {
        for (int i = 0; i < GUIBar::getUpl(); i++) {
            mvwprintw(progressbar, 3, i + 6, "", 97);
            waddch(progressbar, 97 | A_ALTCHARSET);
        }
        wattroff(progressbar, A_STANDOUT);
        mvwprintw(progressbar, 5, 6, "%d %%", GUIBar::getUpl());

        //simulo il display dei file..

        mvwprintw(progressbar, 5, 89, "Resource_file_%d", (GUIBar::getUpl() * 3) + 1);
        wrefresh(progressbar);
        wgetch(progressbar);

    }

    if (GUIBar::getUpl() == 100) {
        mvwprintw(progressbar, 6, 40, "LOADING COMPLETE!!!");
        mvprintw(25, 57, "Press any key to continue");
        wrefresh(progressbar);
        getch();
    }
    refresh();
    endwin();
}

void GUIProgressBar::attach() {
    subject->subscribe(this);

}

void GUIProgressBar::detach() {
    subject->unsubscribe(this);
}