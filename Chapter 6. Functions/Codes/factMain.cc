#include <iostream>
#include "Chapter6.hpp"

int main() {
  std::cout << "Absolute value of -10 is " << absolute_value(-10) << '\n';

  std::cout << "Factorial of 5 is " << fact(5) << '\n';

  std::cout << "Function called_times is called " << called_times() << " times " << '\n';
  std::cout << "Function called_times is called " << called_times() << " times " << '\n';
  std::cout << "Function called_times is called " << called_times() << " times " << '\n';

  return 0;
}

