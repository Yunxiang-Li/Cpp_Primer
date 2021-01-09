#include <iostream>
#include <list>
#include <algorithm>
#include <string>

int main() {
  std::list<std::string> myList;
  std::string element;
  std::cout << "Please input a sequence of string!" << '\n';
  while (std::cin >> element)
    myList.emplace_back(element);

  int numCount = std::count(myList.cbegin(), myList.cend(), "str");

  std::cout << "Number count of \"str\" is: " << numCount << '\n';

  return 0;
}
