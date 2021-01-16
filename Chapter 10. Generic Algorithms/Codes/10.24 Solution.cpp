#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

bool check_size(const int i, const std::string::size_type& sz)
{
  return i > sz;
}

int main()
{
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::string str{"primer"};
  
  std::vector<int>::const_iterator iter =
      std::find_if(vec.cbegin(), vec.cend(), std::bind(check_size, std::placeholders::_1, str.size()));
      
  std::cout << "First element in the vector which has value greater than the string's size is " << *iter;

  return 0;
}
