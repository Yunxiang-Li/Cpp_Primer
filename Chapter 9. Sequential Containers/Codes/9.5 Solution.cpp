#include <iostream>
#include <vector>

std::vector<int>::iterator func(std::vector<int>::iterator begin, std::vector<int>::iterator end, int value) {
  for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
    if (*iter == value)
      return iter;
  return end;
}
