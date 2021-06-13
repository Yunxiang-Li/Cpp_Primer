#include "ReadStr.hpp"
#include <vector>

int main()
{
    std::vector<std::string> vec;
    ReadStr readStr;
    std::string temp;
    temp = readStr();

    while(!temp.empty()) {
        vec.emplace_back(temp);
        temp = readStr();
    }

    for (const std::string& eachStr : vec)
        std::cout << eachStr << '\n';

}
