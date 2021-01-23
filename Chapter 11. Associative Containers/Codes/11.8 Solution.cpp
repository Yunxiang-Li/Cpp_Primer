#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<std::string> excludedWords{"hello", "and", "hi"};
  std::string word;
  while (std::cin >> word) {
    if (std::find(excludedWords.cbegin(), excludedWords.cend(), word) != excludedWords.cend())
      std::cout << "One excluded word found!\n";
    else
      excludedWords.push_back(word);
  }

  std::cout << "Output all exclude words one by one\n";
  for (const std::string& str : excludedWords)
    std::cout << str << " ";
  return 0;
}
