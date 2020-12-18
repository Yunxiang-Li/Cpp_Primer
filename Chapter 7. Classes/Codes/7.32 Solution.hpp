#include <vector>
#include <string>

#ifndef EX7_32_HPP
#define EX7_32_HPP

class Screen;

class Window_mgr {
 public:
  using ScreenIndex = std::vector<Screen>::size_type;
  inline void clear(ScreenIndex);

 private:
  std::vector<Screen> screens;

};

class Screen {

  friend void Window_mgr::clear(ScreenIndex);

 public:
  using pos = std::string::size_type;

  // First constructor: default constructor.
  Screen() =default;
  // Second constructor.
  Screen(pos height, pos width) : m_height(height),
                                  m_width(width),
                                  m_contents(height * width, ' ')
  {
  };
  // Third constructor.
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

  inline Screen set(pos r, pos c, char ch);
  inline Screen set(char c);

  Screen display(std::ostream& os);
  const Screen display(std::ostream& os) const;

  inline Screen move(pos r, pos c);

 private:
  inline void do_display(std::ostream& os) const {
    os << m_contents;
  };

  pos m_cursorPos{0};
  pos m_height{0};
  pos m_width{0};
  std::string m_contents;

};

Screen Screen::move(pos r, pos c) {
  pos rowIdx = r * m_width;
  m_cursorPos = rowIdx + c;
  return *this;
}

Screen Screen::set(char c) {
  m_contents[m_cursorPos] = c;
  return *this;
}

Screen Screen::set(pos r, pos c, char ch) {
  pos rowIdx = r * m_width;
  m_contents[rowIdx + c] = ch;
  return *this;
}

Screen Screen::display(std::ostream &os) {
  do_display(os);
  return *this;
}

const Screen Screen::display(std::ostream &os) const {
  do_display(os);
  return *this;
}

void Window_mgr::clear(ScreenIndex i) {
  if (i >= screens.size())
    return;
  Screen& s = screens[i];
  s.m_contents = std::string(s.m_height * s.m_width, ' ');
}

#endif
