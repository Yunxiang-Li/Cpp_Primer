#include <iostream>
#include <map>
#include <string>
#include <utility>

int main()
{
  std::map<std::string, std::size_t> word_count;
  std::string word;
  while (std::cin >> word) {
    auto ret = word_count.insert({word, 1});
    if (!ret.second)
      ++((ret.first) -> second);
  }

  // Print the content of the map.
  for (const std::pair<const std::string, std::size_t> w : word_count)
    std::cout << w.first << " " << w.second
              << ((w.second > 1) ? " times" : " time") << std::endl;

  return 0;
}
