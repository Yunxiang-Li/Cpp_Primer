#include <string>
#include <iostream>
#include <functional>
#include <map>

int add(int first, int second) {
    return (first + second);
}

auto mod = [](int first, int second) -> int {return first % second;};

struct myDiv {
 public:
  int operator() (int first, int second) {return first / second;}
};

std::map<std::string , std::function<int(int, int)>> binops = {
    {"+", add},
    {"-", std::minus<int>()},
    {"*", [](int first, int second) -> int {return first * second;}},
    {"/", myDiv()},
    {"%", mod}
};

int main()
{
    std::cout << "\nplease input in this format: int (operator) int !\n";
    int n1, n2;
    std::string s;
    std::cin >> n1 >> s >> n2;

    std::cout << binops[s](n1, n2);

    return 0;
}
