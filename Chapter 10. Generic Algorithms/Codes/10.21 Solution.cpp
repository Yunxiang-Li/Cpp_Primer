#include <iostream>

int main()
{

  int local{10};

  auto decrementToZero = [&]() -> bool {
                                        if (local == 0)
                                          return true;
                                        else {
                                          --local;
                                          return false;
                                        }
  };

  while (!decrementToZero())
    std::cout << "local integer's current value is " << local << '\n';

  return 0;
}
