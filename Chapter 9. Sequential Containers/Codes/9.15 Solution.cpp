#include <vector>

bool compareTwoVec(std::vector<int>& vec1, std::vector<int>& vec2) {
  if (vec1.size() != vec2.size())
    return false;

  for (std::vector<int>::size_type idx = 0; idx != vec1.size(); ++idx)
    if (vec1[idx] != vec2[idx])
      return false;

  return true;
}

