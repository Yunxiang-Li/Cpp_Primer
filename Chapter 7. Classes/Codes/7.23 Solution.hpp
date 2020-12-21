#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>

class Screen {
 public:
  using pos = std::string::size_type;

  Screen() =default;
  Screen(pos height, pos width, char c) : m_height(height),
                                          m_width(width),
                                          m_contents(height * width, c)
  {
  };

  inline char get() const {
    return m_contents[m_cursorPos];
  };

  inline char get(pos r, pos c) const {
    return m_contents[r * m_width + c];
  };

  inline Screen& move(pos r, pos c);

 private:
  pos m_cursorPos{0};
  pos m_height{0};
  pos m_width{0};
  std::string m_contents;

};

Screen& Screen::move(pos r, pos c) {
  pos rowIdx = r * m_width;
  m_cursorPos = m_contents[rowIdx + c];
  return *this;
}

#endif
