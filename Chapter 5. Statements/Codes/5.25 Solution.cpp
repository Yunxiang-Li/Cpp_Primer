#include <iostream>
#include <stdexcept>

int main() {

  int a, b;

  std::cout << "Please input two integers for division!" << '\n';

  while (std::cin >> a >> b) {
    try {
      if (b == 0)
        throw std::runtime_error("The divisor cannot be zero!");
      std::cout << "Result of " << a << " / " << b << " is " << a / b << '\n';
      std::cout << "You can input another two integers for division!" << '\n';
    }
    catch (std::runtime_error &error) {
      std::cout << error.what() << '\n';
      std::cout << "Please input another two valid integers for division!" << '\n';
    }

  }

  return 0;
}
