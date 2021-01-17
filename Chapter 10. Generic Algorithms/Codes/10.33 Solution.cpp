#include <iostream>
#include <iterator>
#include <fstream>

int main()
{
  std::ifstream ifs("abc.txt");
  std::ofstream ofsOdd, ofsEven;

  // Set one istream_iterator and two ostream_iterators.
  std::istream_iterator<int> istream_iterator(ifs), istream_endIter;
  std::ostream_iterator<int> ostream_iterator_odd(ofsOdd, " ");
  std::ostream_iterator<int> ostream_iterator_even(ofsEven, "\n");

  // Write odd elements to ofsOdd and even elements to ofsEven.
  while (istream_iterator != istream_endIter) {
    if (*istream_iterator % 2) {
      *ostream_iterator_odd++ = *istream_iterator++;
    }
    *ostream_iterator_even++ = *istream_iterator++;
  }

  return 0;
}
