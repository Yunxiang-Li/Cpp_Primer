#include <iostream>
#include <string>

int main()
{
  std::string str{"ab2c3d7R4E6"};
  std::string numStr{"0123456789"};
  std::string alphabetStr{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  std::cout << "First find each numeric character" << '\n';
  for (std::string::size_type pos = 0; (pos = str.find_first_not_of(alphabetStr, pos)) != std::string::npos; ++pos)
    std::cout << "Find one numeric character: " << str[pos] << '\n';

  std::cout << "Next find each alphabetic character" << '\n';
  for (std::string::size_type pos = 0; (pos = str.find_first_not_of(numStr, pos)) != std::string::npos; ++pos)
    std::cout << "Find one alphabetic character: " << str[pos] << '\n';

  return 0;
}
