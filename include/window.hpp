#pragma once

#include <ncurses.h>

namespace xgreety {

// Class responsible for managing ncurses windows
class Window {
 private:
  WINDOW* win;     // Pointer to the ncurses window object
  int yMax, xMax;  // Maximum dimensions of the window (height, width)
  int yBeg, xBeg;  // Coordinates for the window's starting position (y, x)

 public:
  // Constructor that initializes the window
  Window();

  // Destructor that cleans up the window resources
  ~Window();
};

}  // namespace xgreety
