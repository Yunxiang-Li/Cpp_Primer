#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, size_t> myMap;
  std::string word;
  while (std::cin >> word) {
    ++myMap[word];
  }
  for (const std::pair<std::string, size_t> eachPair : myMap)
    std::cout << eachPair.first << " appears " << eachPair.second <<
    ((eachPair.second >= 1) ? " times" : " time") << '\n';
  std::cout << std::endl;
  
  return 0;
}
