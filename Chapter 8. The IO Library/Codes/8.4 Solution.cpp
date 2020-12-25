#include <fstream>
#include <vector>

void readFileToVec(const std::string& fileName, std::vector<std::string> vec) {
  std::ifstream inFile(fileName);

  if (inFile) {
    std::string eachLine;
    while (std::getline(inFile, eachLine))
      vec.push_back(eachLine);
  }
}
