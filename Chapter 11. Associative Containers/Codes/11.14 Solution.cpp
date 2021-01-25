#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

int main()
{
  std::map<std::string, std::vector<std::pair<std::string, std::string>>> familyChildrenMap;
  std::string lastName, childName, childBirthday;

  std::cout << "Please input family last name first and end with a space!\n";
  std::cout << "Please next input all children's names and their birthdays bound with the family last name!\n";
  while (std::cin >> lastName) {
    while (std::cin >> childName >> childBirthday)
      familyChildrenMap[lastName].emplace_back(childName, childBirthday);
  }

  std::string newLastName{"David"};
  std::vector<std::pair<std::string, std::string>> ChildBirthdayVec;
  ChildBirthdayVec.emplace_back("Liu", "1996-1-1");
  familyChildrenMap[newLastName] =  ChildBirthdayVec;
  familyChildrenMap[newLastName].emplace_back("Bowie", "2000-5-7");

  for (const auto &eachPair : familyChildrenMap) {
    std::cout << "Current family last name is " << eachPair.first <<
              " And its children's names and birthdays are ";
    for (const auto &element : eachPair.second)
      std::cout << element.first << ", " << element.second << ', ';
    std::cout << '\n';
  }
  return 0;
}
