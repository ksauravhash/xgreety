#pragma once

namespace xgreety {

// Class responsible for handling the greeter screen and user interaction
class Greeter {
 private:
  int yMax, xMax;  // Variables to store the maximum screen dimensions
  int yBeg, xBeg;  // Variables to store the beginning coordinates of the screen

 public:
  Greeter();  // Constructor to initialize the screen

  ~Greeter();  // Destructor to clean up resources

  // Function to configure ncurses settings
  void configure();

  // Function to run the greeter screen and show the welcome message
  void run();
};
}  // namespace xgreety