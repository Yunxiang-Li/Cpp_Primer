#include <iostream>
#include <string>
#include <list>

void elimDups(std::list<std::string>& words)
{
  words.sort();
  words.unique();
}

int main()
{
  std::list<std::string> myList = {"dog", "dog", "deliver", "kite", "rough", "rough", "rough"};
  elimDups(myList);
  for (const std::string& element : myList)
    std::cout << element << " ";
  std::cout << std::endl;
}
