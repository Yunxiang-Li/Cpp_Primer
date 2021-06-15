#ifndef EX7_40_HPP
#define EX7_40_HPP

#include <istream>

class Tree {
 public:
  Tree() =default;
  Tree(int height, int width, unsigned int branch, unsigned int age): m_height(height), m_width(width),
                                                                      m_branch(branch), m_age(age) { }
  Tree(std::istream &in) {
    in >> m_height >> m_width >> m_branch >> m_age;
  }
 
 explicit operator bool() { return (m_age >= 100) ? true : false; }

 private:
  int m_height{0};
  int m_width{0};
  unsigned int m_branch{1};
  unsigned int m_age{1};
};

#endif 
