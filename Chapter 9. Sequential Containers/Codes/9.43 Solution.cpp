#include <iostream>
#include <string>

void replaceOldWithNew(std::string& oriStr, const std::string& oldValStr, const std::string& newValStr) {
 for (auto iter = oriStr.begin(); iter != oriStr.end(); ++iter) {
   std::string temp(iter, iter + oldValStr.size());
   if (temp == oldValStr) {
      iter = oriStr.erase(iter, iter + oldValStr.size());
      iter = oriStr.insert(iter, newValStr.cbegin(), newValStr.cend());
   }
 }
}

int main()
{
  std::string s{"tho thru apt vs"};
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

  std::cout << "Replace fourth value" << '\n';
  replaceOldWithNew(s, "vs", "versus");
  std::cout << "Current string is: " << s << '\n';

  return 0;
}
