#include "login_box.hpp"

#include <ncurses.h>

#include <iostream>

namespace xgreety {
LoginBox::LoginBox() {
  keypad(win, true);
}

LoginBox::LoginBox(int nlines, int ncols, int begin_y, int begin_x)
    : Window(nlines, ncols, begin_y, begin_x) {
  keypad(win, true);
}

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

  int labelLength = 10;                // 10 chars
  int formWidth = labelLength + cols;  // "Username: " (9) + 1 space + input box width
  int startX = (xMax / 2) - (formWidth / 2) - 3;
  int startY = (yMax / 2) - (lines);

  int labelX = startX;
  int usernameY = startY;
  int passwordY = startY + 4;

  int boxX = labelX + 10 + xBeg;
  int usernameBoxY = startY + yBeg - 1;
  int passwordBoxY = usernameBoxY + 4;

  // ------------------- Print Labels for the Input Fields -------------------

  // Print "Username:" label above the username input box
  // Positioned to align nicely with the input box horizontally
  mvwprintw(win, usernameY, labelX, "Username: ");

  // Print "Password:" label above the password input box
  // Uses the same horizontal alignment as "Username:"
  mvwprintw(win, passwordY, labelX, "Password: ");

  wrefresh(win);  // Refresh to ensure the labels appear on screen

  // ------------------- Create Username Input Box -------------------

  // Create a new window for the username input field
  // Vertically aligned just below the "Username:" label
  // Horizontally placed to start just after the "Username:" label
  // Assumes "Username: " is 9 characters wide, so input box starts at xMax/2 - 9
  WINDOW* usernameBox = newwin(lines, cols, usernameBoxY, boxX);
  box(usernameBox, 0, 0);  // Draw a border around the input box
  wrefresh(usernameBox);   // Show the username input box on screen

  // ------------------- Create Password Input Box -------------------

  // Similar setup for the password input box, placed below the username box
  WINDOW* passwordBox = newwin(lines, cols, passwordBoxY, boxX);
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

  wmove(win, 0, 0);

  // Final refresh to make sure both boxes are up to date
  wrefresh(usernameBox);
  wrefresh(passwordBox);
}

void LoginBox::handleInput(int ch) {
  if (ch == KEY_LEFT) {
    if (usernameChoice - 1 >= 0) usernameChoice--;
  } else if (ch == KEY_RIGHT) {
    usernameChoice = (usernameChoice + 1) % usernames.size();
  }
  wmove(win, 0, 0);
  std::cout << (ch == KEY_LEFT) << std::endl;
  wrefresh(win);
}
}  // namespace xgreety