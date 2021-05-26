#include "HasPtr.hpp"

int main() {
    HasPtr hp1("str1");

    std::cout << "=== copy constructor ===\n";
    HasPtr hp2 = hp1;
    std::cout << *hp1.getPs() << std::endl;
    std::cout << *hp2.getPs() << std::endl;

    std::cout << "=== copy-assignment operator ===\n";
    HasPtr hp3;
    hp3 = hp1;
    std::cout << *hp1.getPs() << std::endl;
    std::cout << *hp3.getPs()<< std::endl;

    std::cout << "=== move constructor ===\n";
    HasPtr hp4 = std::move(hp1);
    //std::cout << hp1.get() << std::endl;  // nullptr
    std::cout << *hp4.getPs() << std::endl;

    std::cout << "=== move-assignment operator ===\n";
    hp1 = std::move(hp4);  // Error, `operator=` is ambiguous.
    std::cout << *hp1.getPs() << std::endl;
    //std::cout << hp4.get() << std::endl;  // nullptr

    return 0;
}
