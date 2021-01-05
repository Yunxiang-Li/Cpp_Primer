#include <iostream>
#include <forward_list>

int main() {
  std::forward_list<int> myFList{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto prev = myFList.before_begin(), curr = myFList.begin();

  while (curr != myFList.end()) {
    if (*curr % 2) {
      prev = myFList.insert_after(prev, *curr);
      ++curr;
      ++prev;
    }
    else {
      curr = myFList.erase_after(prev);
    }
  }

  for (const int element : myFList) {
    std::cout << element << ' ';
  }
  
  return 0;
}
