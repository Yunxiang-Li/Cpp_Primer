#include <iostream>

// Return the plural version of word if ctr is greater than 1
std::string make_plural(size_t ctr, const std::string &word, const std::string &ending = "s")
{
  return (ctr > 1) ? word + ending : word;
}

int main() {
  std::cout << "Tests for make_plural function which has default value for ending parameter\n";

  std::cout << "\nSingular version of word success by default value is ";
  std::cout << make_plural(1, "success") << '\n';
  std::cout << "Singular version of word success by non-default value is ";
  std::cout << make_plural(1, "success", "es") << '\n';

  std::cout << "Plural version of word success by default value is ";
  std::cout << make_plural(2, "success") << '\n';
  std::cout << "Plural version of word success by non-default value is ";
  std::cout << make_plural(2, "success", "es") << '\n';

  std::cout << "\nSingular version of word failure by default value is ";
  std::cout << make_plural(1, "failure") << '\n';
  std::cout << "Singular version of word failure by non-default value is ";
  std::cout << make_plural(1, "failure", "es") << '\n';

  std::cout << "Plural version of word failure by default value is ";
  std::cout << make_plural(2, "failure") << '\n';
  std::cout << "Plural version of word failure by non-default value is ";
  std::cout << make_plural(2, "failure", "es") << '\n';
}
