#include <iostream>
#include <string>

void replaceOldWithNew(std::string& oriStr, const std::string& oldValStr, const std::string& newValStr) {
  for (std::string::size_type idx = 0; idx < oriStr.size(); ++idx) {
    if (oriStr.substr(idx, oldValStr.size()) == oldValStr) {
      oriStr.replace(idx, oldValStr.size(), newValStr);
      idx += newValStr.size();
    }
  }
}

int main()
{
  std::string s{"tho thru apt vs vs"};
  std::cout << "Original string is: " << s << '\n';

  std::cout << "Try to replace a non-exist value" << '\n';
  replaceOldWithNew(s, "asap", "as soon as possible");
  std::cout << "Current string is: " << s << '\n';

  std::cout << "Replace first value" << '\n';
  replaceOldWithNew(s, "tho", "though");
  std::cout << "Current string is: " << s << '\n';

  std::cout << "Replace second value" << '\n';
  replaceOldWithNew(s, "thru", "through");
  std::cout << "Current string is: " << s << '\n';

  std::cout << "Replace third value" << '\n';
  replaceOldWithNew(s, "apt", "apartment");
  std::cout << "Current string is: " << s << '\n';

  std::cout << "Replace last two values" << '\n';
  replaceOldWithNew(s, "vs", "versus");
  std::cout << "Current string is: " << s << '\n';

  return 0;
}
