#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> myList{};
  std::reverse_copy(vec.cbegin() + 3, vec.cend() - 2, std::back_inserter(myList));

  std::cout << "Copy 3rd elements to 7th element from vec to myList\n";

  for (const int element : myList)
    std::cout << element << " ";

  return 0;
}
