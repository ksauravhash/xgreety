#pragma once

#include <ncurses.h>

#include <string>
#include <vector>

#include "window.hpp"

namespace xgreety {

/**
 * @brief Represents a login interface built on top of an ncurses window.
 *
 * LoginBox is responsible for displaying username/password fields,
 * navigating between user options, and handling text input.
 * Inherits from the Window base class to reuse window setup and cleanup logic.
 */
class LoginBox : public Window {
 private:
  int usernameChoice = 0;              // Index of the currently selected username
  std::vector<std::string> usernames;  // List of possible usernames to choose from
  std::string password;                // Stores the entered password

 public:
  /**
   * @brief Default constructor.
   * Initializes a basic login box without explicit dimensions/position.
   */
  LoginBox();

  /**
   * @brief Parameterized constructor.
   * Initializes the login box with given dimensions and screen position.
   *
   * @param nlines Height of the login box window.
   * @param ncols Width of the login box window.
   * @param begin_y Y-coordinate for the top-left corner of the box.
   * @param begin_x X-coordinate for the top-left corner of the box.
   */
  LoginBox(int nlines, int ncols, int begin_y, int begin_x);

  /**
   * @brief Loads or generates a list of usernames.
   * Intended to populate the `usernames` vector with system or mock usernames.
   */
  void getUsernames();

  /**
   * @brief Draws the login UI elements on the screen.
   * Includes labels, input boxes, and username list.
   */
  void draw();

  /**
   * @brief Handles keyboard input for interacting with the login box.
   *
   * @param ch The character or key code input by the user.
   * Used to navigate usernames or input credentials.
   */
  void handleInput(int ch);
};

}  // namespace xgreety
