#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::unique_ptr<std::string> unique_ptrOne(new std::string("unique"));
    //std::unique_ptr<std::string> unique_ptrTwo(unique_ptrOne);
    //std::unique_ptr<std::string> unique_ptrThree = unique_ptrOne;

    std::cout << *unique_ptrOne << '\n';
    unique_ptrOne.reset();
    return 0;
}
