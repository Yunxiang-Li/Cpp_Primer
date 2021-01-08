#include <string>
#include <fstream>
#include <iostream>

std::string findLongestWordWithNoAscendersAndDescenders(std::ifstream& ifstream) {
  std::string res{""};
  std::string currWord;
  while (ifstream >> currWord) {
    if (currWord.find_first_of("bdfghijklpqty") == std::string::npos && currWord.size() > res.size())
      res.assign(currWord);
  }
  return res;
}
