#include "Screen.hpp"

Screen& Screen::move(pos r, pos c) {
  pos rowIdx = r * m_width;
  m_cursorPos = m_contents[rowIdx + c];
  return *this;
}

