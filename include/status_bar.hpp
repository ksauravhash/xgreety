#pragma once

#include <chrono>
#include <string>
#include <vector>
#include "window.hpp"

namespace xgreety {
class StatusBar : public Window {
 private:
  short int currentActive = 0;
  std::vector<short int> div_ratios;
  std::vector<short int> sizes;
  
  // Time tracking for automatic updates
  std::chrono::time_point<std::chrono::system_clock> lastUpdate;
  std::string cachedTime;
  std::string cachedDate;

  void drawText();
  void drawDate();
  void drawTime();
  
  /**
   * @brief Updates the cached time and date strings.
   * Called when a second has passed to refresh the display.
   */
  void updateTimeCache();
 public:
  StatusBar();
  StatusBar(int nlines, int ncols, int begin_y, int begin_x);

  void configure();

  void draw();
  void handleInput(int ch);
};
}  // namespace xgreety