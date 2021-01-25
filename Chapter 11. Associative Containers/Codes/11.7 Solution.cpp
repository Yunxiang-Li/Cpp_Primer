#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
  std::map<std::string, std::vector<std::string>> familyNamesMap;
  std::string lastName, childName;

  std::cout << "Please input family last name first and end with a space!\n";
  std::cout << "Please next input all children's names bound with the family last name!\n";
  while (std::cin >> lastName) {
    while (std::cin >> childName)
      familyNamesMap[lastName].push_back(childName);
  }

  std::string newLastName{"David"};
  std::vector<std::string> newChildNames;
  newChildNames.push_back("Liu");
  familyNamesMap[newLastName] =  newChildNames;
  familyNamesMap[newLastName].push_back("Bowie");

  for (const std::pair<std::string, std::vector<std::string>> &eachPair : familyNamesMap) {
    std::cout << "Current family last name is " << eachPair.first <<
    " And its children's names are ";
    for (const std::string &element : eachPair.second)
      std::cout << element << ", ";
    std::cout << '\n';
  }
  return 0;
}
