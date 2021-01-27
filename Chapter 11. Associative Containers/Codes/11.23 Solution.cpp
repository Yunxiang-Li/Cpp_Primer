#include <iostream>
#include <map>
#include <string>
#include <utility>

int main()
{
  std::multimap<std::string, std::string> familyChildrenMap;
  std::string lastName, childName;
  std::cout << "Please input children names first and then the family's last name bound to all these children names\n";
  while (std::cin >> childName >> lastName)
    familyChildrenMap.emplace(lastName, childName);

  for (const std::pair<const std::string, std::string> eachPair : familyChildrenMap)
    std::cout << eachPair.second << " " << eachPair.first << std::endl;

  return 0;
}
