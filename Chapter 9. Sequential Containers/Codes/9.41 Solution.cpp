#include <iostream>
#include <vector>
#include <string>

int main()
{

  std::vector<char> vec{'a', 'b', 'c', 'd', 'e'};

  std::string str(vec.cbegin(), vec.cend());

  for (const char element : str)
    std::cout << element << ' ';

  return 0;
}
