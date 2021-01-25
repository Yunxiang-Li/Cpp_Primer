#include <vector>
#include <iostream>
#include <utility>
#include <string>

int main() {
  std::string str;
  int i;
  std::vector<std::pair<std::string, int>> vec;
  std::cout << "Please input pairs of strings and integers\n";
  while (std::cin >> str >> i) {
    vec.emplace_back(str, i);
  }

  for (const auto eachPair : vec)
    std::cout << "Current pair's key is " << eachPair.first << " ,value is " << eachPair.second << '\n';

  return 0;
}
