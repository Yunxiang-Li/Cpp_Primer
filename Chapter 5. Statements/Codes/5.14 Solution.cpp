#include <iostream>

int main() {

 std::string prevWord, currWord, maxCountWord;
 int currCount = 0, maxCount = 0;

 while (std::cin >> currWord) {
   if (currWord == prevWord)
     ++currCount;
   else {
     prevWord = currWord;
     currCount = 1;
   }

   if (currCount > maxCount) {
     maxCountWord = prevWord;
     maxCount = currCount;
   }
 }

  if (maxCount == 0)
    std::cout << "No repeated word!" << '\n';
  else
    std::cout << "Word " << maxCountWord << " repeated " << maxCount << " times!" << '\n';

  return 0;
}
