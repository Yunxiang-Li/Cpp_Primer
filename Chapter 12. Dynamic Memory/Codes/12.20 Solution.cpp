#include "StrBlob.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream ifs("myFile.txt");
    StrBlob blob;
    std::string eachLine;

    while (std::getline(ifs, eachLine)) {
        blob.push_back(eachLine);
    }

    for (StrBlobPtr pBegin(blob), pEnd(blob.end()); pBegin != pEnd; pBegin.incr()) {
        std::cout << pBegin.deref() << '\n';
    }

    return 0;
}
