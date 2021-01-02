#include <iostream>
#include <list>
#include <deque>

void copyListToTwoDeque(const std::list<int>& list, std::deque<int>& oddValueDQ, std::deque<int>& evenValueDQ) {
  for (auto iter = list.cbegin(); iter != list.cend(); ++iter) {
    if ((*iter % 2) == 1)
      oddValueDQ.emplace_back(*iter);
    else
      evenValueDQ.emplace_back(*iter);
  }
}

int main() {
  std::list<int> myList{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::deque<int> oddDeque;
  std::deque<int> evenDeque;

  copyListToTwoDeque(myList, oddDeque, evenDeque);

  for (const int oddElement : oddDeque)
    std::cout << oddElement << ' ';

  std::cout << '\n';

  for (const int evenElement : evenDeque)
    std::cout << evenElement << ' ';

  return 0;
}

