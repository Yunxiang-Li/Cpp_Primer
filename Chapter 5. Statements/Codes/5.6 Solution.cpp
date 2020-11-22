#include <iostream>
#include <vector>

int main() {

  std::vector<std::string> scores {"F", "D", "C", "B", "A", "A++"};

  int grade{0};

  while (std::cin >> grade) {
    std::string letterGrade;
    letterGrade = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];
    letterGrade += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";

    std::cout << letterGrade << '\n';
  }

  return 0;
}
