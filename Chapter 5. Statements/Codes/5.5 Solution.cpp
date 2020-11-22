#include <iostream>
#include <vector>

int main() {

  std::vector<std::string> scores {"F", "D", "C", "B", "A", "A++"};

  int grade{0};

  while (std::cin >> grade) {
    std::string letterGrade;
    if (grade < 60)
      letterGrade = scores[0];
    else {
      letterGrade = scores[(grade - 50) / 10];
      if (grade != 100) {
        if (grade % 10 > 7)
          letterGrade += "+";
        else if (grade % 10 < 3)
          letterGrade += "-";
      }
    }

    std::cout << letterGrade << '\n';
  }

  return 0;
}
