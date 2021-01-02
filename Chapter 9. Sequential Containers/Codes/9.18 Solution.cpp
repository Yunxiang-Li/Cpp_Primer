#include <iostream>
#include <deque>

int main() {
  std::string inputWord;
  std::deque<std::string> myDeque;

  while (std::cin >> inputWord) {
    myDeque.emplace_back(inputWord);
  }

  for (std::deque<std::string>::const_iterator iter = myDeque.cbegin(); iter != myDeque.cend(); ++iter)
    std::cout << *iter << ' ';

  return 0;
}

