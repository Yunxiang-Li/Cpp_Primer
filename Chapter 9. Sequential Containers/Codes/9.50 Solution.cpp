#include <string>
#include <iostream>
#include <vector>

int getVectorIntSum(const std::vector<std::string>& vec) {
  int res{0};
  for (const std::string& element : vec)
    res += std::stoi(element, 0, 10);

  return res;
}

float getVectorFloatSum(const std::vector<std::string>& vec) {
  float res{0.0};
  for (const std::string& element : vec)
    res += std::stof(element);

  return res;
}

int main() {
  std::vector<std::string> vec{"1.1", "2.2", "3.3", "4.4", "5.5"};
  std::cout << "Sum of vector elements in int form is: " << getVectorIntSum(vec);
  std::cout << "\nSum of vector elements in float form is: " << getVectorFloatSum(vec);
}
