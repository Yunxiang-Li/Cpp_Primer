#include <iostream>
#include <map>
#include <string>

int main()
{

  std::multimap<std::string, std::string> author_work_map{{"ERNEST HEMINGWAY", "Anna Karenina"},
      {"ERNEST HEMINGWAY", "Buddenbrooks"}, {"GEORGE R.R. MARTIN", "Game of Thrones"}};

  for (auto pair : author_work_map)
    std::cout << "Author is " << pair.first << " and relative book is " << pair.second << '\n';

  std::string author{"ERNEST HEMINGWAY"};
  std::string bookName{"Buddenbrooks"};

  std::multimap<std::string, std::string>::iterator iter = author_work_map.find(author);
  while (iter != author_work_map.cend()) {
    if (iter != author_work_map.cend() && iter -> second == bookName)
      iter = author_work_map.erase(iter);
    else
      ++iter;
  }

  std::cout << '\n';
  for (auto pair : author_work_map)
    std::cout << "Author is " << pair.first << " and relative book is " << pair.second << '\n';

  return 0;
}
