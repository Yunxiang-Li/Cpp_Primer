#include <iostream>

int main() {

  char ch;
  unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, blankCnt = 0, tabCnt = 0, newlineCnt = 0,
      ffCnt = 0, flCnt = 0, fiCnt = 0;
  char prev;

  // Use std::noskipws to discard all blank char before first non-blank char.
  while (std::cin >> std::noskipws >> ch) {
    // if ch is a vowel, increment the appropriate counter
    switch (ch) {
      case 'a' :
      case 'A' :
        ++aCnt;
        break;

      case 'e' :
      case 'E' :
        ++eCnt;
        break;

      case 'i':
      {
        if (prev == 'f')
          ++fiCnt;
      }
      case 'I':
        ++iCnt;
        break;

      case 'o' :
      case 'O' :
        ++oCnt;
        break;

      case 'u' :
      case 'U' :
        ++uCnt;
        break;

      case ' ' :
        ++blankCnt;
        break;

      case '\t' :
        ++tabCnt;
        break;

      case '\n' :
        ++newlineCnt;
        break;

      case 'f':
      {
        if (prev == 'f')
          ++ffCnt;
      }
        break;

      case 'l':
      {
        if (prev == 'f')
          ++flCnt;
      }

      default:
        break;
    }
    prev = ch;
  }

  std::cout << "Number of vowel a(A): \t" << aCnt << '\n'
       << "Number of vowel e(E): \t" << eCnt << '\n'
       << "Number of vowel i(I): \t" << iCnt << '\n'
       << "Number of vowel o(O): \t" << oCnt << '\n'
       << "Number of vowel u(U): \t" << uCnt << '\n' << "Number of blank: \t"
       << blankCnt << '\n' << "Number of tab char: \t" << tabCnt << '\n'
       << "Number of new line: \t" << newlineCnt << '\n'
       << "Number of char sequence ff: \t" << ffCnt << '\n'
       << "Number of char sequence fi: \t" << fiCnt << '\n'
       << "Number of char sequence fl: \t" << flCnt << '\n';

  return 0;
}
