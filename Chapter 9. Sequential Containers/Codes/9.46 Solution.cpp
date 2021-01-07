#include <iostream>
#include <string>

std::string addPrefixAndSuffix(const std::string& nameStr, const std::string& prefixStr, const std::string& suffixStr) {
  std::string res(nameStr);
  res.insert(0, prefixStr);
  res.insert(res.size(), suffixStr);
  return res;
}

int main()
{
  std::string s1{"Tom"};
  std::string s1_res = addPrefixAndSuffix(s1, "Mr.", ",Jr.");
  std::cout << s1_res << '\n';

  std::string s2{"Mary"};
  std::string s2_res = addPrefixAndSuffix(s2, "Ms.", ",III.");
  std::cout << s2_res << '\n';

  return 0;
}
