#pragma once

#include "window.hpp"

namespace xgreety {
class ErrorMessage : public Window {
  ErrorMessage();
  ErrorMessage(int nlines, int ncols, int begin_y, int begin_x);
};
}  // namespace xgreety