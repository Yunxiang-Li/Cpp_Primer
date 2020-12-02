#include <iostream>
#include <vector>

void print(const std::vector<int> &vec, std::vector<int>::iterator iter) {
  if (iter == vec.end())
    return;
  std::cout << *iter++ << ' ';
  print(vec, iter);
}

int main() {
  std::cout << "Please input a sequence of integers and I will print each recursively!\n";
  int eachElement;
  std::vector<int> vec;

  while (std::cin >> eachElement) {
    vec.push_back(eachElement);
  }

  print(vec, vec.begin());

}
