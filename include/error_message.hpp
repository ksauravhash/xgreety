#pragma once

#include "window.hpp"

namespace xgreety {
class ErrorMessage : public Window {
 public:
  ErrorMessage();
  ErrorMessage(int nlines, int ncols, int begin_y, int begin_x);

  void draw();
  void handleInput(int ch);
};
}  // namespace xgreety