#include <iostream>
#include <vector>
#include <list>
#include <cstring>

int main() {
  char cArrayOne[]{"abcdefg"};
  char cArrayTwo[]{"abcdefg"};
  std::vector<char*> roster1{cArrayOne};
  std::list<char*> roster2{cArrayTwo};
  bool res = std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
  std::cout << "The result of std::equal function is " << std::boolalpha << res << '\n';

  int res2 = std::strcmp(cArrayOne, cArrayOne);
  std::cout << "The result of std::strcmp function is " << res2;
  return 0;
}
