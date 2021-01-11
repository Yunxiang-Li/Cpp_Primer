#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void printEachElement(const std::vector<std::string>& vec) {
  for (const std::string& element : vec)
    std::cout << element << ' ';
}

void elimDups(std::vector<std::string>& words) {
  std::cout << "\nVector's elements before sort are: \n";
  printEachElement(words);

  std::sort(words.begin(), words.end());
  std::cout << "\nVector's elements after sort are: \n";
  printEachElement(words);

  std::vector<std::string>::iterator endUnique = std::unique(words.begin(), words.end());
  std::cout << "\nVector's elements after unique are: \n";
  printEachElement(words);

  words.erase(endUnique, words.end());
  std::cout << "\nVector's elements after erase are: \n";
  printEachElement(words);
}

int main() {
  std::vector<std::string> vec;
  std::cout << "Please input a sequence of strings with repeated strings!" << '\n';
  std::string word;
  while (std::cin >> word)
    vec.emplace_back(word);

  elimDups(vec);

  return 0;
}
