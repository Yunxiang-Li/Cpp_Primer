#include <iostream>
#include <map>
#include <string>

int main()
{

  std::map<int, std::string> map = {{1, "ss"}, {2, "sz"}};

  std::map<int, std::string>::key_type map_subscript_type = 1;

  std::map<int, std::string>::mapped_type map_return_type = map[map_subscript_type];

  return 0;
}
