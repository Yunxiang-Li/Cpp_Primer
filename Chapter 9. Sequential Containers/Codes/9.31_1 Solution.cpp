#include <iostream>
#include <list>

int main() {
  std::list<int> myList{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto iter = myList.begin();

  while (iter != myList.end()) {
    if (*iter % 2) {
      iter = myList.insert(iter, *iter);
      ++iter;
      ++iter;
    }
    else {
      iter = myList.erase(iter);
    }
  }

  for (const int element : myList) {
    std::cout << element << ' ';
  }
}
