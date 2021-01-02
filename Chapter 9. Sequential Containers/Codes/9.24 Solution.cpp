#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec;
  std::cout << vec.at(0) << '\n';
  std::cout << vec[0] << '\n';
  std::cout << vec.front() << '\n';
  std::cout << *vec.begin() << '\n';

  return 0;
}
