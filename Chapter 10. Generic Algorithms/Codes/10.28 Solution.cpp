#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>


int main()
{

  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> myList;
  std::deque<int> myDeque;
  std::vector<int> myVec;

  std::copy(vec.cbegin(), vec.cend(), std::back_inserter(myList));
  std::copy(vec.cbegin(), vec.cend(), std::front_inserter(myDeque));
  std::copy(vec.cbegin(), vec.cend(), std::inserter(myVec, myVec.begin()));

  std::cout << "Check myList's each element after back_inserter!" << '\n';
  for (const int element : myList)
    std::cout << element << ' ';

  std::cout << "\nCheck myDeque's each element after front_inserter!" << '\n';
  for (const int element : myDeque)
    std::cout << element << ' ';

  std::cout << "\nCheck myVec's each element after inserter!" << '\n';
  for (const int element : myVec)
    std::cout << element << ' ';

  return 0;
}
