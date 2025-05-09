#include "login_box.hpp"

namespace xgreety {
LoginBox::LoginBox() {}

LoginBox::LoginBox(int nlines, int ncols, int begin_y, int begin_x)
    : Window(nlines, ncols, begin_y, begin_x) {}

void LoginBox::draw() {}

void LoginBox::handleInput(int ch) {}
}  // namespace xgreety