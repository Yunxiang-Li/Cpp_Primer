#include <iostream>
#include <vector>
#include <list>

int main() {
  std::list<int> myList = {1, 2 , 3, 4 ,5};
  std::vector<int> myVec = {6, 7, 8, 9, 10};

  std::vector<double> listVec(myList.begin(), myList.end());
  for (std::vector<double>::const_iterator iter = listVec.cbegin(); iter != listVec.cend(); ++iter)
    std::cout << *iter << ' ';

  std::vector<double> vecVec(myVec.begin(), myVec.end());
  for (const double element : vecVec)
    std::cout << element << ' ';
}

