#include "QueryResult.hpp"
#include "StrVec.hpp"
#include <iostream>

void runQueries(std::ifstream& infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.m_query(s)) << std::endl;
    }
}

int main()
{
    std::ifstream file("../text.txt");
    runQueries(file);
}
