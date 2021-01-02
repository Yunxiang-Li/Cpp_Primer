#include <iostream>
#include <deque>

int main() {
  std::string inputWord;
  std::deque<std::string> myDeque;

  while (std::cin >> inputWord) {
    myDeque.emplace_back(inputWord);
  }

  for (std::deque<std::string>::iterator iter = myDeque.begin(); iter != myDeque.end(); ++iter)
    std::cout << *iter << ' ';

  return 0;
}

