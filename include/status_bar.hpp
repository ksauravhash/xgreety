#pragma once

#include <vector>
#include "window.hpp"
namespace xgreety {
class StatusBar : public Window {
  private:
  short int currentActive = 0;
  std::vector<short int> div_ratios;
  std::vector<short int> sizes;

  void drawText();
  void drawDate();
  void drawTime();
 public:
  StatusBar();
  StatusBar(int nlines, int ncols, int begin_y, int begin_x);

  void configure();

  void draw();
  void handleInput(int ch);
};
}  // namespace xgreety