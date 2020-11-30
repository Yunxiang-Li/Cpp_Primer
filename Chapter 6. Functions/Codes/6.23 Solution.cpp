#include <iostream>

void print(int* const pi)
{
  if (pi)
    std::cout << *pi << std::endl;
}

void print(const char* p)
{
  if (p)
    while (*p)
      std::cout << *p++;
  std::cout << std::endl;
}

void print(const int* beg, const int* end)
{
  while (beg != end)
    std::cout << *beg++ << " ";
  std::cout << std::endl;
}

void print(const int ia[], size_t size)
{
  for (size_t i = 0; i != size; ++i)
    std::cout << ia[i] << " ";
  std::cout << std::endl;
}

int main()
{
  int i = 0, j[2] = {0, 1};
  char ch[3] = "ab";

  print(ch);
  print(std::begin(j), std::end(j));
  print(&i);
  print(j, std::end(j) - std::begin(j));
}
