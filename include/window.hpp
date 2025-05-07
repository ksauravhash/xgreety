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

 private:
  WINDOW* win;     ///< Pointer to the ncurses window
  int yMax, xMax;  ///< Height and width of the window
  int yBeg, xBeg;  ///< Starting position of the window
};

}  // namespace xgreety
