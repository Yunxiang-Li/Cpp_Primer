#include <iostream>

int main() {

  char ch;
  unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, blankCnt = 0, tabCnt = 0, newlineCnt = 0;

  while (std::cin >> ch) {
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

      case 'i' :
      case 'I' :
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

      default:
        break;
    }
  }

  std::cout << "Number of vowel a(A): \t" << aCnt << '\n'
       << "Number of vowel e(E): \t" << eCnt << '\n'
       << "Number of vowel i(I): \t" << iCnt << '\n'
       << "Number of vowel o(O): \t" << oCnt << '\n'
       << "Number of vowel u(U): \t" << uCnt << '\n' << "Number of blank: \t"
       << blankCnt << '\n' << "Number of tab char: \t" << tabCnt << '\n'
       << "Number of new line: \t" << newlineCnt << '\n';

  return 0;
}
