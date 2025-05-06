#pragma once

namespace xgreety {

class Greeter {
 private:
  int yMax, xMax, yBeg, xBeg;

 public:
  Greeter();

  ~Greeter();

  void configure();

  void run();
};
}  // namespace xgreety