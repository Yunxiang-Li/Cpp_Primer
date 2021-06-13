#ifndef STRINGBOUNDTEST_HPP
#define STRINGBOUNDTEST_HPP

#include <cstddef>
#include <string>

class StringBoundTest {
 public:
  StringBoundTest(size_t lower, size_t upper) : m_lowerBound(lower), m_upperBound(upper) {};

  bool operator()(const std::string&) const;

 private:
  size_t m_lowerBound;
  size_t m_upperBound;
};

#endif
