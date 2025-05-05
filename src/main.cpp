#include <ncurses.h>

#include "greeter.hpp"

int main() {
  xgreety::Greeter g;
  g.configure();
  g.run();
  return 0;
}
