#include <iostream>

void reset(int& input) {
  input = 0;
}

int main() {

  std::cout << "Please input the integer variable that you want to reset to zero!" << '\n';
  int input;

  while (std::cin >> input) {
    std::cout << "Input value is " << input << '\n';
    reset(input);
    std::cout << "After reset, input value is now " << input << '\n';

    std::cout << "You can input another value for resetting or exit the program!" << '\n';
  }

  return 0;
}

