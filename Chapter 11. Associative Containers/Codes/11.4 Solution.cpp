#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main()
{
  std::map<std::string, size_t> myMap;
  std::string word;
  while (std::cin >> word) {
    for (char& c : word)
      c = std::tolower(c);

    std::string::iterator iter = std::remove_if(word.begin(), word.end(), ispunct);
    word.erase(iter, word.end());
    ++myMap[word];
  }
  for (const std::pair<std::string, size_t> eachPair : myMap)
    std::cout << eachPair.first << " appears " << eachPair.second <<
    ((eachPair.second >= 1) ? " times" : " time") << '\n';
  std::cout << std::endl;
}
