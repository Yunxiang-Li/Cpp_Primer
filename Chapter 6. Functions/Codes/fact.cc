#include "Chapter6.hpp"

int absolute_value(int input)
{

  return ((input) < 0 ? -input : input);

}

int fact(int val)
{
  if (val == 0 || val == 1)
    return 1;
  return val * fact(val - 1);
}

size_t called_times()
{
  static int time;
  return time++;
}
