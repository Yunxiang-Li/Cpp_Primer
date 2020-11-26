#include <iostream>

int main() {

  std::string currStr, prevStr;

  std::cout << "Please input a sequence of strings!" << '\n';

  while (std::cin >> currStr) {
    if (!std::isupper(currStr[0])) {
      prevStr = "";
      std::cout << "Input string's first letter is not an uppercase letter, please input another string!" << '\n';
      continue;
    }

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
