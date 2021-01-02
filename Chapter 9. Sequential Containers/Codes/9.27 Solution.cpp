#include <iostream>
#include <forward_list>

int main()
{
  std::forward_list<int> forward_list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto prevIter = forward_list.cbefore_begin();
  auto currIter = forward_list.cbegin();

  while (currIter != forward_list.cend()) {
    if (*currIter % 2)
      currIter = forward_list.erase_after(prevIter);
    else {
      prevIter = currIter;
      ++currIter;
    }
  }

  for (const int& element : forward_list)
    std::cout << element << ' ';

  return 0;
}
