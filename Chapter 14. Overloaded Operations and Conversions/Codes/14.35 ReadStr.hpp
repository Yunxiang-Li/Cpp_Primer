#ifndef READSTR_HPP
#define READSTR_HPP

#include <istream>
#include <iostream>

class ReadStr {
 public:
    ReadStr(std::istream& istream = std::cin) : m_istream(istream) {};
    std::string operator()() const;

 private:
  std::istream& m_istream;
};

#endif
