#include <ncurses.h>

int main() {
  // Start cursor mode
  initscr();

  printw("Welcome to xgreety - WIP");

  // Print it on the screen
  refresh();
  // Wait for user input
  getch();
  // End curses mode
  endwin();
  return 0;
}
