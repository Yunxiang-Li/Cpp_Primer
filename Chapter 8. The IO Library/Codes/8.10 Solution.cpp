#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

void storeEachLine(std::ifstream& inputFile) {
  if (inputFile)
    std::cerr << "No input file provided!\n";
  else {
    std::string eachLine;
    std::vector<std::string> vec;
    while (std::getline(inputFile, eachLine)) {
      vec.push_back(eachLine);
    }

    for (std::string &str : vec) {
      std::istringstream inputSstream(str);
      std::string currStr;
      while (inputSstream >> currStr) {
        std::cout << "Current string is " << currStr;
      }
    }
  }
}
