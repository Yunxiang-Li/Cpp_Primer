#include <iostream>
#include <vector>
#include <list>

int main() {
  std::list<const char*> myList{"abc", "def", "ofc"};

  std::vector<std::string> myVec;
  myVec.assign(myList.begin(), myList.end());

  for (const std::string& str : myVec)
    std::cout << str << ' ';
}

