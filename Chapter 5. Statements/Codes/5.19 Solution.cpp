#include <iostream>

int main() {

  std::string response;

  do {
    std::cout << "Please input two strings!" << '\n';
    std::string str1, str2;
    std::cin >> str1 >> str2;

    (str1.size() < str2.size()) ? std::cout << str1 << " is less than " << str2 << " !\n" :
    (str2.size() < str1.size()) ? std::cout << str2 << " is less than " << str1 << " !\n" :
    std::cout << "Both strings have same length!" << '\n';

    std::cout << "Input Y if you want to compare two more strings!" << '\n';
    std::cin >> response;

  }
  while (!response.empty() && response == "Y");

  return 0;
}
