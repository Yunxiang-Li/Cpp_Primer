#include <iostream>
#include <stdexcept>

int main() {

  int a, b;

  std::cin >> a >> b;
  if (b == 0)
    throw std::runtime_error("The divisor cannot be zero!");

  std::cout << "Result of " << a << " / " << b << " is " << a / b;

  return 0;
}
