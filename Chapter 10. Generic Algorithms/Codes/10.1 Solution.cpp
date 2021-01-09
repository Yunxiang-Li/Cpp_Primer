#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> vec;
  int element;
  std::cout << "Please input a sequence of int!" << '\n';
  while (std::cin >> element)
    vec.emplace_back(element);

  int numCount = std::count(vec.cbegin(), vec.cend(), 1);

  std::cout << "Number count of 1 is: " << numCount << '\n';

  return 0;
}

