#include <iostream>

void swap(int& first, int& second) {
  if (first != second) {
    int temp = first;
    first = second;
    second = temp;
  }
}

int main() {

  std::cout << "Please input two integers and their values will be swapped!" << '\n';
  int first, second;

  while (std::cin >> first >> second) {
    std::cout << "First value is " << first << ", second value is " << second << '\n';
    swap(first, second);
    std::cout << "Swap two values " << '\n';
    std::cout << "Now first value is " << first << ", second value is " << second << '\n';

    std::cout << "You can input another two values for swapping or exit the program!" << '\n';
  }

  return 0;
}
