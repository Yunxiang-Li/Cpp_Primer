#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

bool valid(const std::string& str);

std::string format(const std::string& str);

void storeEachLine(std::ifstream& inputFile) {
  // will hold a line and word from input, respectively
  std::string line, word;
  std::vector<PersonInfo> people; // will hold all the records from the input
  std::istringstream record;

  // read the input a line at a time until cin hits end-of-file (or another error)
  while (getline(std::cin, line)) {
    PersonInfo info;
    record.clear();
    // create an object to hold this record's data
    record.str(line);
    // bind record to the line we just read
    record >> info.name;// read the name
    while (record >> word)// read the phone numbers
      info.phones.push_back(word);// and store them
    people.push_back(info); // append this record to people}
  }

  for (const auto& entry : people) {
    std::ostringstream formatted, badNums;
    for (const auto& nums : entry.phones)
      if (!valid(nums))
        badNums << " " << nums;
      else
        formatted << " " << format(nums);
    if (badNums.str().empty())
      std::cout << entry.name << " " << formatted.str() << '\n';
    else
      std::cerr << "input error: " << entry.name << " invalid number(s) "
           << badNums.str() << '\n';
  }
}
