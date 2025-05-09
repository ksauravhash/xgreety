#pragma once
#include <ncurses.h>

namespace xgreety {

/**
 * @class Window
 * @brief A wrapper around an ncurses WINDOW, handling lifecycle and basic operations.
 */
class Window {
 public:
  /**
   * @brief Constructs a full-screen window using default terminal size.
   */
  Window();

  /**
   * @brief Constructs a window with given dimensions and position.
   * @param nlines Number of lines (height) of the window.
   * @param ncols Number of columns (width) of the window.
   * @param begin_y Y-coordinate of the upper-left corner of the window.
   * @param begin_x X-coordinate of the upper-left corner of the window.
   */
  Window(int nlines, int ncols, int begin_y, int begin_x);

  /**
   * @brief Destructor that releases resources used by the window.
   */
  ~Window();

  /**
   * @brief Returns the height of the window in rows.
   * @return Height in rows.
   */
  int getHeight() const;

  /**
   * @brief Returns the width of the window in columns.
   * @return Width in columns.
   */
  int getWidth() const;

  /**
   * @brief Returns the Y-coordinate of the window’s origin.
   * @return Start Y position.
   */
  int getStartY() const;

  /**
   * @brief Returns the X-coordinate of the window’s origin.
   * @return Start X position.
   */
  int getStartX() const;

  /**
   * @brief Reads a single input character from this window.
   *
   * This function wraps the `wgetch()` ncurses call, allowing the window
   * instance to directly capture input. It returns the character or key
   * code entered by the user while the window is active.
   *
   * @return The input character or special key code (e.g., KEY_UP, KEY_ENTER).
   */
  int getWindowInput() const;

  /**
   * @brief Virtual function to draw the window's contents.
   *
   * This function should be implemented by derived classes to handle
   * the drawing/rendering of the window's content. This could include
   * things like text, borders, UI elements, etc. The derived class should
   * use ncurses functions like `wrefresh()` and `mvwprintw()` to render
   * content onto the window.
   *
   * @note This is a pure virtual function and must be overridden in
   *       derived classes.
   */
  virtual void draw() = 0;

  /**
   * @brief Virtual function to handle input from the user.
   *
   * This function is called to handle the user input within the window.
   * The derived class should implement how to process the input (e.g.,
   * key presses) based on its specific functionality. This could involve
   * moving a cursor, updating UI elements, or triggering specific actions.
   *
   * @param ch The character or key pressed by the user.
   *
   * @note This is a pure virtual function and must be overridden in
   *       derived classes.
   */
  virtual void handleInput(int ch) = 0;

 protected:
  WINDOW* win;     ///< Pointer to the ncurses window
  int yMax, xMax;  ///< Height and width of the window
  int yBeg, xBeg;  ///< Starting position of the window
};

}  // namespace xgreety
