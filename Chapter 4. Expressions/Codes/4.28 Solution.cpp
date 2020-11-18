#include <iostream>

int main() {

  std::cout << "bool\t\tis " << sizeof(bool) << " bytes." << '\n';
  std::cout << "char\t\tis " << sizeof(char) << " bytes." << '\n';
  std::cout << "wchar_t\t\tis " << sizeof(wchar_t) << " bytes." << '\n';
  std::cout << "char16_t\tis " << sizeof(char16_t) << " bytes." << '\n';
  std::cout << "char32_t\tis " << sizeof(char32_t) << " bytes." << '\n';
  std::cout << "short\t\tis " << sizeof(short) << " bytes." << '\n';
  std::cout << "int\t\tis " << sizeof(int) << " bytes." << '\n';
  std::cout << "long\t\tis " << sizeof(long) << " bytes." << '\n';
  std::cout << "long long\tis " << sizeof(long long) << " bytes." << '\n';
  std::cout << "float\t\tis " << sizeof(float) << " bytes." << '\n';
  std::cout << "double\t\tis " << sizeof(double) << " bytes." << '\n';
  std::cout << "long double\tis " << sizeof(long double) << " bytes." << '\n';
  std::cout << '\n';

  return 0;
}
