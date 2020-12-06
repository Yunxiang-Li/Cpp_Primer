#include <iostream>
#include <vector>

const int add (const int& a , const int& b) {
  return a + b;
}

const int subtract (const int& a , const int& b) {
  return a - b;
}

const int multiply (const int& a , const int& b) {
  return a * b;
}

const int divide (const int& a , const int& b) {
  return b == 0 ? INT32_MIN : a / b;
}

int main()
{
  const int func(const int&, const int&);
  using fp = decltype(func);
  std::vector<fp*> vec;
  vec.push_back(add);
  vec.push_back(subtract);
  vec.push_back(multiply);
  vec.push_back(divide);
}
