#include "status_bar.hpp"

#include "window.hpp"

namespace xgreety {
StatusBar::StatusBar() {}
StatusBar::StatusBar(int nlines, int ncols, int begin_y, int begin_x)
    : Window(nlines, ncols, begin_y, begin_x) {}

void StatusBar::draw() {}

void StatusBar::handleInput(int ch) {}

}  // namespace xgreety