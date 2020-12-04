#include <iostream>
#include <vector>

//#define NDEBUG

void print(const std::vector<int> &vec, std::vector<int>::iterator iter) {

#ifndef NDEBUG
  std::cout << "File name: " << __FILE__ << " ,Function name: " << __FUNCTION__ << " at line " << __LINE__ <<
  "\n Compiled on " << __DATE__ << " at " << __TIME__ << "\nCurrent vector size is " << vec.size() << '\n';
#endif

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
