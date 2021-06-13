#include "StringBoundTest.hpp"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream fin("../test.txt");

    StringBoundTest testOne(1, 10);
    StringBoundTest testTwo(1, 9);
    int resOne = 0;
    int resTwo = 0;

    for (std::string word; fin >> word;)
    {
        if(testOne(word))
            ++resOne;
        if (testTwo(word))
            ++resTwo;
    }

    std::cout << resOne << '\n';
    std::cout << resTwo << '\n';

    return 0;
}
