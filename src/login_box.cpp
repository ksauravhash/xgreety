#include "login_box.hpp"

#include <ncurses.h>

namespace xgreety {
LoginBox::LoginBox() {}

LoginBox::LoginBox(int nlines, int ncols, int begin_y, int begin_x)
    : Window(nlines, ncols, begin_y, begin_x) {}

void LoginBox::getUsernames() {
  usernames.push_back("user");
  usernames.push_back("tomato");
}

void LoginBox::draw() {
  // Clear the main window and draw a box around it
  wclear(win);
  box(win, 0, 0);
  wrefresh(win);  // Refresh the main window to reflect the changes

  // Dimensions for the input boxes
  int cols = 20;  // Width of the input boxes
  int lines = 3;  // Height of the input boxes

  char password[50];  // Buffer to store the entered password

  // Print labels for the input fields in the main window
  mvwprintw(win, 2, 1, "Username: ");
  mvwprintw(win, 5, 1, "Password: ");
  wrefresh(win);  // Refresh to ensure the labels appear on screen

  // ------------------- Create Username Input Box -------------------

  // Create a new window for the username input
  // Position: (yBeg + 1, xBeg + 11) accounts for placing it to the right of the "Username:" label
  WINDOW* usernameBox = newwin(lines, cols, yBeg + 1, xBeg + 11);
  box(usernameBox, 0, 0);  // Draw a border around the input box
  wrefresh(usernameBox);   // Show the box on screen

  // ------------------- Create Password Input Box -------------------

  // Similar setup for the password input box, placed below the username box
  WINDOW* passwordBox = newwin(lines, cols, yBeg + 4, xBeg + 11);
  box(passwordBox, 0, 0);
  wrefresh(passwordBox);  // Show the password box on screen

  // ------------------- Input Handling -------------------

  // Show the cursor (value 2 = highly visible, terminal dependent)
  curs_set(2);

  // Enable input echo for the username
  echo();

  // Move the cursor inside the username box (1,1) due to border offset
  wmove(usernameBox, 1, 1);

  // Pre-fill the username box with the selected username (from a list)
  wprintw(usernameBox, "%s", usernames[usernameChoice].c_str());
  wrefresh(usernameBox);  // Ensure pre-filled username appears

  // Disable echo to hide password input
  noecho();

  // Move cursor to the password box and allow input
  wmove(passwordBox, 1, 1);

  // Read password securely into buffer (input will not be displayed)
  wgetnstr(passwordBox, password, sizeof(password) - 1);

  // Hide the cursor again
  curs_set(0);

  // Final refresh to make sure both boxes are up to date
  wrefresh(usernameBox);
  wrefresh(passwordBox);
}

void LoginBox::handleInput(int ch) {}
}  // namespace xgreety