#include <iostream>

int main() {

  std::string currStr, prevStr;

  std::cout << "Please input a sequence of strings!" << '\n';

  while (std::cin >> currStr) {
    if (currStr == prevStr)
      break;
    prevStr = currStr;
  }

  if (std::cin.eof())
    std::cout << "no word was repeated!" << '\n';
  else
    std::cout << currStr << " occurs twice in succession!" << '\n';

  return 0;
}
