#include "status_bar.hpp"

#include <ncurses.h>

#include <vector>

#include "window.hpp"

namespace xgreety {
StatusBar::StatusBar() {}
StatusBar::StatusBar(int nlines, int ncols, int begin_y, int begin_x)
    : Window(nlines, ncols, begin_y, begin_x) {}

void StatusBar::configure() {
  keypad(win, true);
  noecho();
  div_ratios.push_back(1);
  div_ratios.push_back(2);
  div_ratios.push_back(1);

  int ratios_sumed = 0;
  for (short int i : div_ratios) ratios_sumed += i;
  for (size_t i = 0; i < div_ratios.size(); i++) sizes.push_back(xMax / div_ratios[i]);
}

void StatusBar::draw() {
    drawText();
    drawDate();
    drawTime();
}

void StatusBar::handleInput(int ch) {}

void StatusBar::drawText() {
}

void StatusBar::drawDate() {}

void StatusBar::drawTime() {}

}  // namespace xgreety