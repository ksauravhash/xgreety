#pragma once

#include <ncurses.h>
#include <string>
#include <vector>
#include "window.hpp"

namespace xgreety {

/**
 * @brief Represents a login interface built on top of an ncurses window.
 *
 * LoginBox handles the drawing of UI elements for login, including username and password fields,
 * and processes user interactions. It is a subclass of the base `Window` class, enabling it to
 * manage an ncurses window with position and size.
 */
class LoginBox : public Window {
 private:
  int usernameChoice = 0;              ///< Index of the currently selected username.
  std::vector<std::string> usernames;  ///< List of system or mock usernames to choose from.
  std::string password;                ///< Stores the entered password as plaintext (to be handled securely).
  
  WINDOW *usernameBox, *passwordBox;   ///< Separate ncurses windows for input fields.
  int usernameY, passwordY, labelX;    ///< Coordinates for rendering UI elements (Y position for inputs and label X offset).
  int currentActive = 0;               ///< Indicates whether the username (0) or password (1) field is active.
  int currentPos = 0;                  ///< Cursor position within the password field.
  bool done;                           ///< Whether the login process has completed or exited.

  /**
   * @brief Helper method to draw the inner components of the login box (labels and borders).
   */
  void handleInnerWindowDraw();

  /**
   * @brief Returns a masked version of the password (e.g., "****") for secure display.
   *
   * @return std::string The masked string with asterisks.
   */
  std::string getMaskedPassword();

 public:
  /**
   * @brief Default constructor.
   * Initializes a basic login box without specifying size or position.
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
   * @brief Loads a list of usernames.
   * This can pull from system accounts or a predefined list for testing.
   */
  void getUsernames();

  /**
   * @brief Draws the login box UI on the screen.
   * Displays labels, boxes, and currently selected username.
   */
  void draw();

  /**
   * @brief Processes user input to interact with the login UI.
   *
   * @param ch Character or key code entered by the user.
   * Supports input navigation, character input, and field switching.
   */
  void handleInput(int ch);

  /**
   * @brief Configures the login box (colors, input modes, etc).
   * Should be called before drawing or running interactions.
   */
  void configure();

  /**
   * @brief Executes the login operation using the captured credentials.
   * Placeholder for integrating authentication backends like PAM.
   */
  void login();
};

}  // namespace xgreety
