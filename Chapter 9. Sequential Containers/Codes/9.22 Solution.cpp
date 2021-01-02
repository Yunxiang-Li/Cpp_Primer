#include <iostream>
#include <vector>

void insertDoubleValue(std::vector<int>& iv, int some_val)
{
  auto cursor = iv.size() / 2;
  auto iter = iv.begin(), mid = iv.begin() + cursor;
  while (iter != mid) {
    if (*iter == some_val) {
      iter = iv.insert(iter, 2 * some_val);
      ++iter;
      ++cursor;
      mid = iv.begin() + cursor;
    }
    ++iter;
  }
}

void print(const std::vector<int>& iv)
{
  for (auto i : iv) std::cout << i << " ";
  std::cout << std::endl;
}

int main()
{
  std::vector<int> iv = {1, 1, 1, 1, 1, 2, 3, 4};
  insertDoubleValue(iv, 1);
  print(iv);
}
