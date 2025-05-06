#include "greeter.hpp"

#include <ncurses.h>
#include <cstdlib>

xgreety::Greeter::Greeter() {
  initscr();
}

xgreety::Greeter::~Greeter() {
  clear();
  endwin();
}

void xgreety::Greeter::configure() {
    getmaxyx(stdscr, yMax, xMax);
    getbegyx(stdscr, yBeg, xBeg);

    noecho();
    cbreak();

    if(!has_colors()) {
        printw("This programs requires the terminal to support colors.");
        exit(-1);
    } 
    start_color();
    use_default_colors();
    keypad(stdscr, true);
    refresh();
}

void xgreety::Greeter::run() {
    printw("Welcome to the initial program.");
    mvprintw(1, 0, "Press any key to exit.");
    refresh();
    getchar();
}
