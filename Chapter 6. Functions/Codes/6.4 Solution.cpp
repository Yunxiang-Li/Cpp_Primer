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

  std::cout << "Please input an unsigned integer and you will get its factorial!" << '\n';

  while(std::cin >> input) {
    if (input < 0) {
      std::cout << "Input integer cannot be a negative integer, please try again!" << '\n';
      continue;
    }
    int res = fact(input);
    std::cout << input << "! is " << res << '\n';

    std::cout << "You can now input another integer or quit the program!" << '\n';
  }
  return 0;
}
