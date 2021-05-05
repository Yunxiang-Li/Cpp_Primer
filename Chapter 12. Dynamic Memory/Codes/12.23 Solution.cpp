#include <cstdlib>
#include <cstring>
#include <iostream>

int main() {
    const char* c1 = "hello";
    const char* c2 = "world";

    std::size_t len = std::strlen(c1) + std::strlen(c2) + 1;
    char* dynamicArray = new char[len]();

    std::strcat(dynamicArray, c1);
    std::strcat(dynamicArray, c2);

    std::cout << "The result of dynamic array is " << dynamicArray << '\n';

    std::string str1 = "hello";
    std::string str2 = "world";

    std::string strRes(str1 + str2);
    std::cout << "The result of string add is " << strRes << '\n';

    delete [] dynamicArray;
    return 0;
}
