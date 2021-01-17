#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <fstream>


int main()
{
  std::vector<std::string> vec;
  std::ifstream ifstream("abc.txt");
  std::istream_iterator<std::string> istream_iterator(ifstream), istream_endIter;
  // Copy file contents into the vector.
  std::copy(istream_iterator, istream_endIter, std::back_inserter(vec));

  // Output the vector's elements.
  std::ostream_iterator<std::string> ostream_iterator(std::cout, " ");
  std::copy(vec.cbegin(), vec.cend(), ostream_iterator);

  std::cout << '\n';

  return 0;
}
