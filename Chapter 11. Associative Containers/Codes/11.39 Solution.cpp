#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

/**
 * Build a map from originals word to transformed words.
 * @param ifs_map a reference of std::ifstream which indicates the transformed map's text file.
 * @return a std::map which mapping from originals word to transformed words.
 */
std::unordered_map<std::string, std::string> buildMap(std::ifstream& ifs_map) {
  std::unordered_map<std::string, std::string> map;
  std::string key, value;
  while (ifs_map >> key && std::getline(ifs_map, value)) {
    if (value.size() > 1)
      map[key] = value.substr(1);
    else
      throw std::runtime_error("No associated values found!");
  }
  return map;
}

/**
 * Try to find and return each word's mapping value, if not find, just return word itself back.
 * @param word a reference of a const std::string which indicates each word we need to process.
 * @param map a reference of a const std::map which mapping from originals word to transformed words.
 * @return a reference of a const std::string which indicates the mapping value of each input word.
 */
const std::string& transform(const std::string& word, const std::unordered_map<std::string, std::string>& map) {
  std::unordered_map<std::string, std::string>::const_iterator iter = map.find(word);
  if (iter != map.cend())
    return iter -> second;
  else
    return word;
}

/**
 * Transform each word to its transformed word.
 * @param ifs_map  a reference of std::ifstream which indicates the transformed map's text file.
 * @param ifs_content  a reference of std::ifstream which indicates the user input text file.
 */
void word_transform(std::ifstream& ifs_map, std::ifstream& ifs_content) {
  std::unordered_map<std::string, std::string> word_transform_map{buildMap(ifs_map)};
  std::string line;
  while (std::getline(ifs_content, line)) {
    std::istringstream sstream(line);
    std::string word;
    bool isFirst{true};
    while (sstream >> word) {
      if (isFirst)
        isFirst = false;
      else
        std::cout << ' ';
      std::cout << transform(word, word_transform_map);
    }
    std::cout << '\n';
  }
}

int main()
{
  std::ifstream ifs_transform_map("transformMap.txt"), ifs_content("inputContent.txt");
  if (ifs_transform_map && ifs_content)
    word_transform(ifs_transform_map, ifs_content);
  else
    std::cerr << "Cannot find required text files!\n";

  return 0;
}
