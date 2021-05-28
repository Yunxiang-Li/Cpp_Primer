#ifndef FOO_HPP
#define FOO_HPP

#include <vector>

class Foo {

 public:
  Foo sorted() const &;
  Foo sorted() &&;

 private:
  std::vector<int> data;
};

#endif
