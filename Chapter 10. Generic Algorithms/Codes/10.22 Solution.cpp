#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

bool strSizeLessThanOrEqualTo(const std::string& str, const std::string::size_type& sz) {
  return str.size() <= sz;
}

int main()
{
  std::vector<std::string> vec{"dog", "in", "deliver", "sword", "clever", "conversation", "nevertheless"};

  std::cout << "Altogether there are " <<
  std::count_if(vec.cbegin(), vec.cend(), std::bind(strSizeLessThanOrEqualTo, std::placeholders::_1, 6))
  << " strings which size are less than or equal to 6!";
  return 0;
}
