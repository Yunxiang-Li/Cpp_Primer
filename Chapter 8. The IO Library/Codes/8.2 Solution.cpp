#include <iostream>

std::istream& func(std::istream& istream) {
  std::string inputStr;
  while (istream >> inputStr) {
    std::cout << inputStr << '\n';
  }
  istream.clear();
  return istream;
}

// Test the func method.
int main() {
  std::istream& res = func(std::cin);
  std::cout << res.rdstate() << '\n';
  return 0;
}
