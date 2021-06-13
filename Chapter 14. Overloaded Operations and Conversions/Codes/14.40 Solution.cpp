#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class StringCompare {
 public:
  bool operator()(const std::string& strOne, const std::string& strTwo) const {
      return (strOne.size() < strTwo.size());
  }
};

class SizeCheck {
 public:
  SizeCheck(const std::string::size_type size) : m_size(size) {};

  bool operator()(const std::string& str) {
      return str.size() >= m_size;
  };

 private:
  const std::string::size_type m_size;
};

class StringPrint {
 public:
  void operator()(const std::string& str) const {
      std::cout << str << " ";
  }
};

void elimdups(std::vector<std::string>& vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

bool check_size(const std::string& s, const std::string::size_type& sz)
{
    return s.size() >= sz;
}

void biggies(std::vector<std::string>& vs, std::size_t sz)
{

    elimdups(vs);

    //! sort by size, but maintain alphabetical order for same size.
    std::stable_sort(vs.begin(), vs.end(),
                     StringCompare());

    //! get an iterator to the first one whose size() is >= sz
    auto wc = find_if(vs.begin(), vs.end(), SizeCheck(sz));

    //! print the biggies
    std::for_each(wc, vs.end(), StringPrint());
}

int main()
{

    std::vector<std::string> v{"a", "a", "in", "dog", "dog", "drivers", "deliver",
                               "fridge", "forever", "provide"};
    std::cout << "The string which has no duplicates and greater than 3 letters are: ";
    biggies(v, 4);
    std::cout << std::endl;

    return 0;
}
