#include <iostream>
#include <vector>
#include <list>

int main() {
  char cArrayOne[]{"abcdefg"};
  char cArrayTwo[]{"abcdefg"};
  std::vector<char*> roster1{cArrayOne};
  std::list<char*> roster2{cArrayTwo};
  int res = std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
  std::cout << res;
  return 0;
}
