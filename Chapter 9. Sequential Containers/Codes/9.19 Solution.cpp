#include <iostream>
#include <list>

int main() {
  std::string inputWord;
  std::list<std::string> myList;

  while (std::cin >> inputWord) {
    myList.emplace_back(inputWord);
  }

  for (std::list<std::string>::const_iterator iter = myList.cbegin(); iter != myList.cend(); ++iter)
    std::cout << *iter << ' ';

  return 0;
}

