#include <iostream>

int fact(int val)
{
  if (val == 0 || val == 1)
    return 1;
  return val * fact(val - 1);
}

int main()
{
  int input;

  std::cout << "Please input an integer and you will get its absolute value!" << '\n';

  int res;

  while(std::cin >> input) {
    if (input < 0)
      res = -input;
    else
      res = input;
    std::cout << input << "'s absolute value is " << res << std::endl;

    std::cout << "You can now input another integer or quit the program!" << '\n';
  }
  return 0;
}
