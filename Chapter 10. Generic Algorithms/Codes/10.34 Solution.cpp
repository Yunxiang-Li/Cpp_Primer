#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec{0, 1, 2, 3, 4, 5};
  std::cout << "First print each element in the vec in original order:\n";
  for (const int element : vec)
    std::cout << element << " ";

  std::cout << "\nThen print each element in reverse order\n";
  for (std::vector<int>:: const_reverse_iterator r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter)
    std::cout << *r_iter << " ";

  return 0;
}
