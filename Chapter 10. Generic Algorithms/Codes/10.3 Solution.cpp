#include <iostream>
#include <vector>
#include <numeric>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int sum = std::accumulate(vec.cbegin(), vec.cend(), 0);
  std::cout << "Sum of all elements is: " << sum << '\n';

  return 0;
}
