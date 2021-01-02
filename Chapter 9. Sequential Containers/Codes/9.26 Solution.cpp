#include <iostream>
#include <vector>
#include <list>

int main()
{
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
  std::vector<int> vec(ia, ia + sizeof(ia) / sizeof(int));
  std::list<int> myList(vec.begin(), vec.end());

  auto listIter = myList.cbegin();
  while (listIter != myList.cend()) {
    if (*listIter % 2)
      listIter = myList.erase(listIter);
    else
      ++listIter;
  }

  auto vecIter = vec.cbegin();
  while (vecIter != vec.cend()) {
    if (!(*vecIter % 2))
      vecIter = vec.erase(vecIter);
    else
      ++vecIter;
  }

  std::cout << "List elements are:" << '\n';
  for (const int element : myList)
    std::cout << element << ' ';

  std::cout << '\n';

  std::cout << "Vector elements are:" << '\n';
  for (const int element : vec)
    std::cout << element << ' ';

  return 0;
}
