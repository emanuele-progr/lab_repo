//
// Created by emanuele on 18/09/16.
//

#include "GUIBar.h"


GUIBar::GUIBar(FileManager *s) : subject(s), upl(0) {

    //inizializzo la finestra di caricamento..

    initscr();
    curs_set(0);
    noecho();
    progressbar = newwin(8, 112, 15, 20);

}

GUIBar::~GUIBar() {
    detach();
    delete progressbar;
}


void GUIBar::draw() {


    box(progressbar, ACS_VLINE, ACS_DIAMOND);
    mvwprintw(progressbar, 1, 3, "LOADING....");

    //simulo un ritardo nell'agg.percentuale dovuto al caricamento..

    wtimeout(progressbar, 200);
    wattron(progressbar, A_STANDOUT);
    if (upl < 101) {
        for (int i = 0; i < upl; i++) {
            mvwprintw(progressbar, 3, i + 6, "", 97);
            waddch(progressbar, 97 | A_ALTCHARSET);
        }
        wattroff(progressbar, A_STANDOUT);
        mvwprintw(progressbar, 5, 6, "%d %%", upl);

        //simulo il display dei file..

        mvwprintw(progressbar, 5, 89, "Resource_file_%d", (upl * 3) + 1);
        wrefresh(progressbar);
        wgetch(progressbar);

    }

    if (upl == 100) {
        mvwprintw(progressbar, 6, 40, "LOADING COMPLETE!!!");
        mvprintw(25, 57, "Press any key to continue");
        wrefresh(progressbar);
        getch();

    }
    wtimeout(progressbar, 0);
    refresh();
    endwin();
}

void GUIBar::update(int up) {
    upl = up;
    draw();
}

void GUIBar::attach() {
    subject->subscribe(this);

}

void GUIBar::detach() {
    subject->unsubscribe(this);
}

int GUIBar::getUpl() const {
    return upl;
}


