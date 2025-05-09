#pragma once

#include <ncurses.h>

#include "window.hpp"
namespace xgreety {
class LoginBox : public Window {
 public:
  LoginBox();
  LoginBox(int nlines, int ncols, int begin_y, int begin_x);

  void draw();
  void handleInput(int ch);
};
}  // namespace xgreety