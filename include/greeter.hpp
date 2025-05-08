#pragma once

namespace xgreety {

// Class responsible for handling the greeter screen and user interaction
class Greeter {
 private:
  int yMax, xMax;  // Variables to store the maximum screen dimensions
  int yBeg, xBeg;  // Variables to store the beginning coordinates of the screen

 public:
  Greeter();  // Constructor to initialize the screen

  ~Greeter();  // Destructor to clean up resources

  /**
   * @brief Configures the terminal settings and initializes the environment.
   *
   * This function sets up the terminal environment for the application. It performs
   * the following key tasks:
   * - Retrieves the screen's maximum dimensions (rows and columns).
   * - Retrieves the starting coordinates of the screen.
   * - Disables terminal echo (so user input is not displayed on screen).
   * - Disables line buffering, allowing input characters to be processed immediately.
   * - Checks if the terminal supports colors; if not, prints an error and exits.
   * - Initializes color support and sets the terminal to use its default color scheme.
   * - Enables keypad input to allow special key recognition (e.g., arrow keys).
   *
   * @note This function assumes that `initscr()` has already been called to initialize ncurses.
   *
   * @exit This method will terminate the program with a non-zero exit code if the terminal does not
   * support colors.
   */
  void configure();

  /**
   * @brief Main loop for managing and handling window interactions.
   *
   * This function runs an infinite loop that draws all windows in `comp_arr`,
   * processes user input, and switches focus between windows when necessary.
   * It supports navigation through the windows using the TAB key and handles
   * input for the currently active window.
   *
   * The method creates a `comp_arr` vector to hold the window components,
   * starting with a `LoginBox`. It continuously draws each window and reads
   * input from the currently active window. If the user presses the TAB key,
   * the focus switches to the next window in the list. Otherwise, the active
   * window processes the input via its `handleInput` method.
   *
   * @note This method runs indefinitely until an external exit condition is met
   *       (e.g., program termination).
   */
  void run();
};
}  // namespace xgreety