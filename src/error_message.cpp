#include "error_message.hpp"

namespace xgreety {
ErrorMessage::ErrorMessage() {}

ErrorMessage::ErrorMessage(int nlines, int ncols, int begin_y, int begin_x)
    : Window(nlines, ncols, begin_y, begin_x) {}

void ErrorMessage::draw() {}

void ErrorMessage::handleInput(int ch) {}

}  // namespace xgreety