#include <iostream>
#include <forward_list>

void findAndInsert(std::forward_list<std::string>& fList, const std::string& str1, const std::string& str2) {
  auto prevIter = fList.cbefore_begin();
  auto currIter = fList.cbegin();

  while (currIter != fList.cend()) {
    if (*currIter == str1) {
      fList.insert_after(currIter, str2);
      return;
    }
    else {
      prevIter = currIter;
      ++currIter;
    }
  }

  fList.insert_after(prevIter, str2);
}
