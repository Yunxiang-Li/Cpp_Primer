#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto iter = vi.begin();
  while (iter != vi.end()) {
    if (*iter % 2) {
      iter = vi.insert(iter, *iter);
      std::advance(iter, 2);
    }
    else
      ++iter;
  }

  for (auto i : vi)
    std::cout << i << " ";

  return 0;
}
