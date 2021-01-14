#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void elimdups(std::vector<std::string>& vs)
{
  std::sort(vs.begin(), vs.end());
  auto new_end = std::unique(vs.begin(), vs.end());
  vs.erase(new_end, vs.end());
}

void biggies(std::vector<std::string>& vs, std::size_t sz)
{

  elimdups(vs);

  //! sort by size, but maintain alphabetical order for same size.
  std::stable_sort(vs.begin(), vs.end(),
                   [](std::string const& lhs, std::string const& rhs) {
                     return lhs.size() < rhs.size();
                   });

  //! get an iterator to the first one whose size() is >= sz
  auto wc = std::stable_partition(vs.begin(), vs.end(),
                         [sz](std::string const& s) { return s.size() >= sz; });

  //! print the biggies
  std::for_each(wc, vs.end(), [](const std::string& s) { std::cout << s << " "; });
}

int main()
{

  std::vector<std::string> v{"a", "a", "in", "dog", "dog", "drivers", "deliver",
                             "fridge", "forever", "provide"};
  std::cout << "The string which has less than 3 letters are: ";
  biggies(v, 3);
  std::cout << std::endl;

  return 0;
}
