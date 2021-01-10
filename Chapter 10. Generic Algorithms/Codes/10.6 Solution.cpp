#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::fill_n(vec.begin(), vec.size(), 0);

  for (const int element : vec)
    std::cout << element << ' ';
  
  return 0;
}
