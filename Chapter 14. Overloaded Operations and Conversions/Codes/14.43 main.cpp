#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

int main()
{
    std::vector<int> vec{5, 11, 15, 25};
    int inputInt;
    std::cin >> inputInt;
    auto predicator = [=] (int i) -> bool {return std::modulus<int>()(inputInt, i) == 0;};

    bool res = std::any_of(vec.begin(), vec.end(), predicator);

    std::cout << (res ? "Yes!" : "No!") << '\n';

    return 0;
}
