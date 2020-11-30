#include <iostream>

int findLarger(const int a, const int* const bPtr) {
  return (a > *bPtr) ? a : *bPtr;
}

int main() {

  int a1 = 10, a2 = 20, a3 = 30;
  int b1 = 15, b2 = 8, b3 = 40;
  int* bPtr1 = &b1, *bPtr2 = &b2, *bPtr3 = &b3;


  int res1 = findLarger(a1, bPtr1);
  std::cout << "Larger one between " << a1 << " and " << b1 << " is " << res1 << '\n';

  int res2 = findLarger(a2, bPtr2);
  std::cout << "Larger one between " << a2 << " and " << b2 << " is " << res2 << '\n';

  int res3 = findLarger(a3, bPtr3);
  std::cout << "Larger one between " << a3 << " and " << b3 << " is " << res3 << '\n';

  return 0;
}
