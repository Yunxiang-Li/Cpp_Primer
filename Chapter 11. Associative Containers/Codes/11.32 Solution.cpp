#include <iostream>
#include <map>
#include <string>
#include <set>

int main()
{

  std::multimap<std::string, std::string> author_work_map{{"ERNEST HEMINGWAY", "Anna Karenina"},
      {"ERNEST HEMINGWAY", "Buddenbrooks"}, {"GEORGE R.R. MARTIN", "Game of Thrones"}};

  std::set<std::string> author_set;
  std::set<std::string> book_set;

  for (auto eachPair : author_work_map) {
    author_set.insert(eachPair.first);
    book_set.insert(eachPair.second);
  }

  std::cout << "Authors are ";
  for (auto author : author_set)
    std::cout << author << " ";

  std::cout << "\nBooks are ";
  for (auto book : book_set)
    std::cout << book << " ";

  return 0;
}
