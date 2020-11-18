#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (int &element : vec)
    element = (element % 2) ? element * 2 : element;

  // Print each element to ensure that the result is correct.
  for (int &element : vec)
    std::cout << element << ' ';

  return 0;
}
