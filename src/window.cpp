#include "window.hpp"

#include <ncurses.h>

#include <stdexcept>

namespace xgreety {

// Constructor: Initializes the window and sets up its properties.
Window::Window() {
  win = newwin(0, 0, 0, 0);  // Create a full-screen window
  if (!win) {
    throw std::runtime_error("Failed to create window (full screen)");
  }
  getmaxyx(win, yMax, xMax);  // Get size
  getbegyx(win, yBeg, xBeg);  // Get starting position
}

Window::Window(int nlines, int ncols, int begin_y, int begin_x) {
  win = newwin(nlines, ncols, begin_y, begin_x);  // Create a window of specified size
  getmaxyx(win, yMax, xMax);
  getbegyx(win, yBeg, xBeg);
  wrefresh(win);  // Display the window
}

// Destructor: Cleans up the window resources when the object is destroyed.
Window::~Window() {
  if (win) {
    wclear(win);  // Clear content
    delwin(win);  // Delete window
  }
}

int Window::getHeight() const {
  return yMax;
}

int Window::getWidth() const {
  return xMax;
}

int Window::getStartY() const {
  return yBeg;
}

int Window::getStartX() const {
  return xBeg;
}

}  // namespace xgreety
