#include <iostream>
#include <vector>

int main() {

  std::vector<int> vec1, vec2;

  int eachElement;

  std::cout << "Please input each element for vec1!" << '\n';

  while (std::cin >> eachElement)
    vec1.push_back(eachElement);

  std::cout << "Please input each element for vec2!" << '\n';

  while (std::cin >> eachElement)
    vec2.push_back(eachElement);

  std::vector<int>::size_type smallerSize = std::min(vec1.size(), vec2.size());

  for (decltype(vec1.size()) i = 0; i != smallerSize; ++i)
    if (vec1[i] != vec2[i]) {
      std::cout << "false" << '\n';
      return 0;
    }

  std::cout << "true" << '\n';

  return 0;
}
