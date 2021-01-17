#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


int main()
{
  // Get int sequences from the standard input.
  std::istream_iterator<int> istream_iterator(std::cin), istream_endIter;
  // Copy int sequences from standard input to the vector and sort all integers.
  std::vector<int> vec(istream_iterator, istream_endIter);
  std::sort(vec.begin(), vec.end());

  // Output the vector's elements.
  std::ostream_iterator<int> ostream_iterator(std::cout, " ");
  std::copy(vec.cbegin(), vec.cend(), ostream_iterator);

  return 0;
}
