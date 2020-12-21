#ifndef EX7_42_HPP
#define EX7_42_HPP

#include <istream>

class Tree {
 public:

  Tree(int height, int width, unsigned int branch, unsigned int age): m_height(height), m_width(width),
                                                                      m_branch(branch), m_age(age) { }
  Tree() : Tree(0, 0, 1, 1) {}

  Tree(std::istream &in) : Tree() {
    in >> m_height >> m_width >> m_branch >> m_age;
  }

 private:
  int m_height{0};
  int m_width{0};
  unsigned int m_branch{1};
  unsigned int m_age{1};
};

#endif
