#include <iostream>

void swapPtr(const int* &aPtr, const int* &bPtr) {
  const int* tempPtr = aPtr;
  aPtr = bPtr;
  bPtr = tempPtr;
}

int main() {

  const int a = 10;
  const int* aPtr = &a;
  const int b = 100;
  const int* bPtr = &b;

  std::cout << "For now, aPtr points to " << *aPtr << " and bPtr points to " << *bPtr << '\n';
  swapPtr(aPtr, bPtr);
  std::cout << "Now swapping two pointers!\n";

  std::cout << "For now, aPtr points to " << *aPtr << " and bPtr points to " << *bPtr << '\n';

  return 0;
}
