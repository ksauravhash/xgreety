#include "login_box.hpp"

#include <ncurses.h>
#include <algorithm>
#include <cctype>

namespace xgreety {
// Default constructor
LoginBox::LoginBox() {}

// Constructor initializing window dimensions and position
LoginBox::LoginBox(int nlines, int ncols, int begin_y, int begin_x)
    : Window(nlines, ncols, begin_y, begin_x) {}

void LoginBox::configure() {
  keypad(win, true);  // Enable arrow keys for the main window

  // Define size of the input boxes
  int cols = 20;  // Width of each input field
  int lines = 3;  // Height including borders

  int labelLength = 10;  // Length of label "Username:" or "Password:"
  int formWidth = labelLength + cols;

  // Calculate the horizontal starting point to center the form
  int startX = (xMax / 2) - (formWidth / 2) - 3;
  // Vertically center the form, placing username box higher than password
  int startY = (yMax / 2) - (lines);

  // Save coordinates for labels
  labelX = startX;
  usernameY = startY;
  passwordY = startY + 4;  // Leave space between fields

  // Determine coordinates of the input boxes (relative to the screen)
  int boxX = labelX + 10 + xBeg;         // 10 = length of label + space
  int usernameBoxY = startY + yBeg - 1;  // Adjust upward to align with label
  int passwordBoxY = usernameBoxY + 4;   // Leave a row between boxes

  // Create new ncurses windows for input fields
  usernameBox = newwin(lines, cols, usernameBoxY, boxX);
  passwordBox = newwin(lines, cols, passwordBoxY, boxX);

  done = false;  // Reset state flag
}

void LoginBox::getUsernames() {
  // Hardcoded example usernames (e.g., can be replaced with real data later)
  usernames.push_back("user");
  usernames.push_back("tomato");
}

void LoginBox::draw() {
  // Clear existing content and draw outer box
  wclear(win);
  box(win, 0, 0);
  wrefresh(win);

  // Display labels above the input boxes
  mvwprintw(win, usernameY, labelX, "Username: ");
  mvwprintw(win, passwordY, labelX, "Password: ");
  wrefresh(win);

  // Draw borders for username and password boxes
  box(usernameBox, 0, 0);
  wrefresh(usernameBox);

  box(passwordBox, 0, 0);
  wrefresh(passwordBox);

  // Set cursor inside the username box initially
  wmove(usernameBox, 1, 1);

  handleInnerWindowDraw();  // Fill in default values or current selections
}

void LoginBox::handleInput(int ch) {
  if (done) {
    noecho();     // Disable echo if login is finished
    curs_set(0);  // Hide cursor
    return;
  }

  if (ch == KEY_DOWN || ch == KEY_UP) {
    // Switch focus between username and password fields
    currentActive = (currentActive + 1) % 2;
  } else {
    if (currentActive == 0) {
      // Navigation within username list
      curs_set(0);
      if (ch == KEY_LEFT && usernameChoice - 1 >= 0) {
        usernameChoice--;
      } else if (ch == KEY_RIGHT) {
        // Loop around the list if at end
        usernameChoice = (usernameChoice + 1) % usernames.size();
      }
    } else {
      // Password entry handling
      if (std::isprint(ch)) {
        // Only add printable characters to password
        password.push_back(ch);
        currentPos++;
      } else if (ch == KEY_BACKSPACE) {
        // Allow deleting characters
        if (!password.empty()) {
          password.pop_back();
          currentPos--;
        }
      }
    }
  }

  // Show cursor if not done and focused on password field
  curs_set(!done && currentActive);
  handleInnerWindowDraw();  // Update UI with new inputs or selections
}

void LoginBox::handleInnerWindowDraw() {
  // Clear previous input contents visually
  mvwprintw(usernameBox, 1, 1, "                  ");
  mvwprintw(passwordBox, 1, 1, "                  ");

  // Highlight currently active field
  attr_t standout = A_STANDOUT;
  if (currentActive == 0) {
    wattron(usernameBox, standout);
  }

  // Add arrows to indicate selectable usernames
  if (usernameChoice > 0) mvwprintw(usernameBox, 1, 1, "<");
  if (usernameChoice < usernames.size() - 1) mvwprintw(usernameBox, 1, 18, ">");

  // Remove highlight after drawing username field
  wattroff(usernameBox, standout);

  // Show selected username
  mvwprintw(usernameBox, 1, 2, "%s", usernames[usernameChoice].c_str());

  // Display password using asterisks
  mvwprintw(passwordBox, 1, 2, "%s", getMaskedPassword().c_str());

  // Move cursor to correct position in password field
  if (currentActive) {
    wmove(passwordBox, 1, (currentPos < 16 ? currentPos : 16) + 2);
  }

  wrefresh(usernameBox);
  wrefresh(passwordBox);
}

std::string LoginBox::getMaskedPassword() {
  std::string masked;
  // Show up to 16 asterisks (to match input box width)
  for (int i = 0; i < std::min(password.length(), (size_t)16); i++) {
    masked.push_back('*');
  }
  return masked;
}
}  // namespace xgreety