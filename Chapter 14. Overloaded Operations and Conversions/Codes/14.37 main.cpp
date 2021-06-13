#include "EqualCheck.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> vec = {1, 0, 1, 0, 0, 1, 0, 1};

    std::replace_if(vec.begin(), vec.end(), EqualCheck(0), -1);

    for (const int i : vec)
        std::cout << i << " ";

    return 0;
}
