#include "StringBoundTest.hpp"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream fin("../test.txt");

    StringBoundTest test(1, 10);
    int res = 0;

    for (std::string word; fin >> word;)
    {
        if (test(word))
            ++res;
    }

    std::cout << res << '\n';

    return 0;
}
