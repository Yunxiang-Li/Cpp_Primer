#include <sstream>
#include <iostream>

std::istream& func(std::istream& istream) {
  std::string inputStr;
  while (istream >> inputStr) {
    std::cout << inputStr;
  }
  istream.clear();
  return istream;
}
