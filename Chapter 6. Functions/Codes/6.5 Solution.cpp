#include <iostream>

int absolute_value(int input)
{
  
  return ((input) < 0 ? -input : input);
  
}

int main()
{
  int input;

  std::cout << "Please input an integer and you will get its absolute value!" << '\n';

  while(std::cin >> input) {

    int ans = absolute_value(input);

    std::cout << input << "'s absolute value is " << ans << '\n';

    std::cout << "You can now input another integer or quit the program!" << '\n';
  }
  return 0;
}
