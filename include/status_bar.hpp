#pragma once

#include "window.hpp"
namespace xgreety {
class StatusBar : public Window {
 public:
  StatusBar();
  StatusBar(int nlines, int ncols, int begin_y, int begin_x);

  void draw();
  void handleInput(int ch);
};
}  // namespace xgreety