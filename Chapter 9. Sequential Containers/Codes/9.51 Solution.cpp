#include <array>
#include <iostream>
#include <string>

class Date {
 public:
  explicit Date(const std::string& str = "");
  void Print();
  unsigned year = 1970;
  unsigned month = 1;
  unsigned day = 1;

 private:
  std::array<std::string, 12> month_names{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  unsigned MonthFromName(const std::string& str);
};

Date::Date(const std::string& str)
{
  if (str.empty()) return;
  std::string delimiters{" ,/"};
  auto month_day_delim_pos = str.find_first_of(delimiters);
  if (month_day_delim_pos == std::string::npos)
    throw std::invalid_argument("This format is not supported now.");
  month = MonthFromName(str.substr(0, month_day_delim_pos));
  auto day_year_delim_pos = str.find_first_of(delimiters, month_day_delim_pos + 1);
  auto day_len = day_year_delim_pos - month_day_delim_pos - 1;
  day = std::stoi(str.substr(month_day_delim_pos + 1, day_len));
  year = std::stoi(str.substr(day_year_delim_pos + 1));
}

void Date::Print()
{
  std::cout << year << "-" << month << "-" << day << "\n";
}

unsigned Date::MonthFromName(const std::string& str)
{
  if (str.empty()) return 0;
  if (std::isdigit(str[0])) return std::stoi(str);
  for (size_t i = 0; i != 12; ++i) {
    if (str.find(month_names[i]) != std::string::npos) return i + 1;
  }
  return 0; //  not found
}

int main()
{
  { //  default case
    auto date = Date();
    date.Print();
  }
  { //  case 0
    auto date = Date("March 11, 2020");
    date.Print();
  }
  { //  case 1:
    auto date = Date("3/4/1987");
    date.Print();
  }
  { //  case 2
    auto date = Date("Dec 22, 1995");
    date.Print();
  }
}
