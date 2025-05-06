#include "greeter.hpp"

#include <ncurses.h>

#include <cstdlib>

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

// Configures ncurses environment settings such as window size, color support, and input handling.
void Greeter::configure() {
  // Get the maximum dimensions of the screen (rows and columns)
  getmaxyx(stdscr, yMax, xMax);

  // Get the screen's starting coordinates
  getbegyx(stdscr, yBeg, xBeg);

  // Disable terminal echo (input won't be displayed on screen)
  noecho();

  // Disable line buffering (allows characters to be read immediately)
  cbreak();

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

// Runs the greeter screen with a welcome message and waits for user input to exit.
void Greeter::run() {
  // Display a welcome message at the top of the screen
  printw("Welcome to the initial program.");

  // Display an instruction at the second line of the screen
  mvprintw(1, 0, "Press any key to exit.");

  // Refresh the screen to update the output
  refresh();

  // Wait for a key press from the user to exit
  getchar();
}

}  // namespace xgreety
