#include <iostream>
#include <initializer_list>

int sum(const std::initializer_list<int>& initial_list) {

  int res{0};

  for (const int &element : initial_list) {
    res += element;
  }

  return res;
}

int main()
{
  int res = sum(std::initializer_list<int>{1, 2, 3, 4, 5});

  std::cout << " The sum of 1-5 is " << res;
}
