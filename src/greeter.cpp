#include "greeter.hpp"

#include <ncurses.h>

#include <cstdlib>
#include <memory>
#include <vector>

#include "login_box.hpp"
#include "window.hpp"

namespace xgreety {

// Constructor: Initializes the ncurses library and sets up the initial state.
Greeter::Greeter() {
  // Initializes ncurses mode (sets up terminal for ncurses functionality)
  initscr();
}

// Destructor: Cleans up the ncurses environment by clearing the screen and ending ncurses mode.
Greeter::~Greeter() {
  clear();   // Clears the screen
  endwin();  // Ends ncurses mode and restores the terminal state
}

void Greeter::configure() {
  // Get the maximum dimensions of the screen (rows and columns)
  getmaxyx(stdscr, yMax, xMax);

  // Get the screen's starting coordinates
  getbegyx(stdscr, yBeg, xBeg);

  // Disable terminal echo (input won't be displayed on screen)
  noecho();

  // Disable line buffering (allows characters to be read immediately)
  cbreak();

  curs_set(0);

  // Check if the terminal supports colors
  if (!has_colors()) {
    // If no color support, print error message and exit
    printw("This program requires the terminal to support colors.");
    exit(-1);
  }

  // Start color functionality
  start_color();
  use_default_colors();  // Use the terminal's default colors
  keypad(stdscr, true);  // Enable keypad input (for special keys like arrows)

  // Refresh screen to apply changes
  refresh();
}

void Greeter::run() {
  std::vector<std::unique_ptr<Window>> comp_arr;
  int boxHeight = 16;
  int boxWidth = 60;
  comp_arr.push_back(std::make_unique<LoginBox>(boxHeight, boxWidth, yMax / 2 - boxHeight / 2,
                                                xMax / 2 - boxWidth / 2));
  LoginBox* loginBox = dynamic_cast<LoginBox*>(comp_arr[0].get());
  loginBox->configure();
  loginBox->getUsernames();
  short int active = 0;  ///< Index of the currently active window

  // Draw all windows in the array
  for (auto& w : comp_arr) {
    w->draw();
  }

  // Main loop to continuously draw windows and handle input
  while (true) {
    // Reference to the currently active window
    Window& active_win = *comp_arr[active];

    // Get input from the active window
    int ch = active_win.getWindowInput();

    // Handle TAB key press to switch focus between windows
    if (ch == '\t') {
      active = (active + 1) % comp_arr.size();  ///< Switch focus to the next window
    } else {
      active_win.handleInput(ch);  ///< Process input for the active window
    }
  }
}

}  // namespace xgreety
