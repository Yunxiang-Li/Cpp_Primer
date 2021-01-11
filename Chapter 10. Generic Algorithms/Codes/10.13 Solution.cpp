#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool predicate(const std::string& str) {
  return str.size() <= 5;
}

int main() {
  std::vector<std::string> words{"hi", "hello", "umbrella", "algorithm", "string"};
  std::vector<std::string>::iterator iter = std::partition(words.begin(), words.end(), predicate);
  while (iter != words.cend()) {
    std::cout << *iter << ' ';
    ++iter;
  }

  return 0;
}
