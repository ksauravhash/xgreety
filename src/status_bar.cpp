#include "status_bar.hpp"

#include <ncurses.h>

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>

#include "window.hpp"

namespace xgreety {

StatusBar::StatusBar() : lastUpdate(std::chrono::system_clock::now()) {}

StatusBar::StatusBar(int nlines, int ncols, int begin_y, int begin_x)
    : Window(nlines, ncols, begin_y, begin_x),
      lastUpdate(std::chrono::system_clock::now()) {}

void StatusBar::configure() {
  keypad(win, true);
  noecho();
  
  // Set up three sections with ratios 1:2:1
  div_ratios.push_back(1);
  div_ratios.push_back(2);
  div_ratios.push_back(1);

  // Calculate sizes based on ratios
  int ratios_sumed = 0;
  for (short int i : div_ratios) ratios_sumed += i;
  for (size_t i = 0; i < div_ratios.size(); i++) {
    sizes.push_back(xMax / ratios_sumed * div_ratios[i]);
  }
  
  // Initialize time cache
  updateTimeCache();
}

void StatusBar::draw() {
  // Check if a second has passed - non-blocking update
  auto now = std::chrono::system_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate);
  
  if (elapsed.count() >= 1) {
    updateTimeCache();
    lastUpdate = now;
  }
  
  // Clear and redraw the status bar
  wclear(win);
  box(win, 0, 0);
  
  drawText();
  drawDate();
  drawTime();
  
  wrefresh(win);
}

void StatusBar::handleInput(int) {
  // Status bar doesn't handle input
}

void StatusBar::updateTimeCache() {
  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  auto local_time = std::localtime(&now_c);
  
  // Format time (HH:MM:SS)
  std::stringstream timeStream;
  timeStream << std::put_time(local_time, "%H:%M:%S");
  cachedTime = timeStream.str();
  
  // Format date (e.g., "Mon Feb 15")
  std::stringstream dateStream;
  dateStream << std::put_time(local_time, "%a %b %d");
  cachedDate = dateStream.str();
}

void StatusBar::drawText() {
  // Left section - display custom text
  int xPos = 2;  // Start position with padding
  mvwprintw(win, 1, xPos, "xgreety v0.1.0");
}

void StatusBar::drawDate() {
  // Middle section - display date
  int xPos = sizes[0] + 2;  // Start of middle section
  mvwprintw(win, 1, xPos, "%s", cachedDate.c_str());
}

void StatusBar::drawTime() {
  // Right section - display time
  int xPos = sizes[0] + sizes[1] + 2;  // Start of right section
  mvwprintw(win, 1, xPos, "%s", cachedTime.c_str());
}

}  // namespace xgreety