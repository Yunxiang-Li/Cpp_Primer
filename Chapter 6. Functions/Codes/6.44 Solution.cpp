#include <iostream>
#include "inline.hpp"

int main() {
  std::string strOne;
  std::string strTwo;

  std::cout << "Please input two strings and the program will check if the first string is shorter "
               "than the second string\n";
  while (std::cin >> strOne >> strTwo) {
    if (isShorter(strOne, strTwo))
      std::cout << strOne <<" is shorter than string " << strTwo;
    else
      std::cout << strOne <<" is longer than or equal to string " << strTwo;
    std::cout << "\nYou can now input two strings again to compare or just quit the program\n";
  }

}
