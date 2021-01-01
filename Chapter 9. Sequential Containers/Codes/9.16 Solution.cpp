#include <vector>
#include <list>

bool compareTwoVec(std::vector<int>& vec, std::list<int>& list) {
  if (vec.size() != list.size())
    return false;

  std::vector<int> listVec(list.begin(), list.end());

  for (std::vector<int>::size_type idx = 0; idx != list.size(); ++idx)
    if (vec[idx] != listVec[idx])
      return false;

  return true;
}

