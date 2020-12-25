#include <fstream>
#include <vector>

void readFileToVec(const std::string& fileName, std::vector<std::string> vec) {
  std::ifstream inFile(fileName);

  if (inFile) {
    std::string eachLine;
    while (inFile >> eachLine)
      vec.push_back(eachLine);
  }
}
