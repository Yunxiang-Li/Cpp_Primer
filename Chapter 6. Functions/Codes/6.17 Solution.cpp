#include <iostream>

bool hasCapital(const std::string& str) {
  for (const char& eachChar : str)
    if (std::isupper(eachChar))
      return true;
  return false;
}

void convertLower(std::string& str) {
  for (char& eachChar : str)
    if (std::isupper(eachChar))
      eachChar = std::tolower(eachChar);
}

int main() {
  std::string str;
  std::cout << "Please input a string, I will check if it has any capital letters!" << '\n';
  std::cout << "Then all letters in this string will be converted to lowercase!" << '\n';

  while (std::cin >> str) {
    std::cout << "Input string is " << str << '\n';
    bool res = hasCapital(str);

    if (res)
      std::cout << "Input string has at least one uppercase letter!" << '\n';
    else
      std::cout << "Input string has no uppercase letter at all!" << '\n';

    convertLower(str);
    std::cout << "Input string's all lowercase version is " << str << '\n';

    std::cout << "You can now input another string or quit the program!" << '\n';
  }

  return 0;
}
