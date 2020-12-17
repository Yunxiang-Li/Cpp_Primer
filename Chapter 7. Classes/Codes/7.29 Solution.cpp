#include <ostream>
#include "Screen.hpp"

Screen Screen::display(std::ostream &os) {
  do_display(os);
  return *this;
}

const Screen Screen::display(std::ostream &os) const {
  do_display(os);
  return *this;
}



