#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

int main()
{

  std::vector<int> vec{0, 0, 1, 1, 2, 3, 4, 5, 5, 5, 5};
  std::list<int> myList;

  std::unique_copy(vec.cbegin(), vec.cend(), std::back_inserter(myList));

  for (const int element : myList)
    std::cout << element << ' ';

  return 0;
}
