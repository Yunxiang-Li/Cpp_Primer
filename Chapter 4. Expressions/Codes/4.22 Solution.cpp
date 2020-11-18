#include <iostream>

int main() {

  int grade{};

  while (std::cin >> grade) {
    // Only use conditional operator.
    std::cout << ((grade > 90) ? "High Pass" : (grade <= 75) ? "Low Pass" : (grade < 60) ? "Fail" : "Pass") << '\n';

    // Use if clauses.
    if (grade > 90)
      std::cout << "High Pass";
    else if (grade < 60)
      std::cout << "Fail";
    else if (grade <= 75)
      std::cout << "Low Pass";
    else
      std::cout << "Pass";
  }

  return 0;
}
