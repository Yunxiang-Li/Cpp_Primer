#include <iostream>

static size_t time = 0;

size_t called_times()
{
  return time++;
}

int main()
{

  // 0 time
  std::cout << "Function called_times is called " << called_times() << " times!" << '\n';
  // 1 time
  std::cout << "Function called_times is called " << called_times() << " times!" << '\n';
  // 2 time
  std::cout << "Function called_times is called " << called_times() << " times!" << '\n';
  // 3 time
  std::cout << "Function called_times is called " << called_times() << " times!" << '\n';
  // 4 time
  std::cout << "Function called_times is called " << called_times() << " times!" << '\n';
  // 5 time
  std::cout << "Function called_times is called " << called_times() << " times!" << '\n';

  return 0;
}
