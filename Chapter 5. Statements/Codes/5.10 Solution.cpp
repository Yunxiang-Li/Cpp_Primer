#include <iostream>

int main() {

  char ch;
  unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

  while (std::cin >> ch) {
    // if ch is a vowel, increment the appropriate counter
    if (ch == 'a' || ch == 'A')
      ++aCnt;
    else if (ch == 'e' || ch == 'E')
      ++eCnt;
    else if (ch == 'i' || ch == 'I')
      ++iCnt;
    else if (ch == 'o' || ch == 'O')
      ++oCnt;
    else if (ch == 'u' || ch == 'U')
      ++uCnt;
  }

  std::cout << "Number of vowel a/A: \t" << aCnt << '\n' << "Number of vowel e/E: \t"
       << eCnt << '\n' << "Number of vowel i/I: \t" << iCnt << '\n'
       << "Number of vowel o/O: \t" << oCnt << '\n' << "Number of vowel u/U: \t"
       << uCnt << '\n';

  return 0;
}
