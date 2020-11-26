#include <iostream>

int fact(unsigned int val)
{
  if (val == 0 || val == 1)
    return 1;
  return val * fact(val - 1);
}

int main()
{
  int j = fact(10);  // j equals 362880 which is the result of fact(10)
  std::cout << "10! is " << j << std::endl;
  return 0;
}
