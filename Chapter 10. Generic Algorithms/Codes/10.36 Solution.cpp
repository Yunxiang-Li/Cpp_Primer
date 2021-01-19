#include <iostream>
#include <list>
#include <algorithm>

int main()
{
  std::list<int> myList{0, 1, 2, 3, 0, 5, 0};
  std::list<int>::const_reverse_iterator r_iter = std::find(myList.crbegin(), myList.crend(), 0);
  unsigned index{0};
  while (r_iter != myList.crend()) {
    ++r_iter;
    ++index;
  }

  std::cout << "Last element with value zero is at the position:" << index;

  return 0;
}
