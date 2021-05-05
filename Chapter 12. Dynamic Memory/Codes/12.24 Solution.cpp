#include <iostream>

int main() {
    std::cout << "Please type the size of string you will input first and then the string "
                 "itself with a space separation!" << '\n';
    int len{0};
    std::cin >> len;
    char* dynamicArray = new char[len + 1]();

    // Ignore 1000 characters or ignore one space.
    std::cin.ignore(1000, ' ');
    std::cin.get(dynamicArray, len + 1);

    std::cout << "The input string is " << dynamicArray << '\n';

    delete[] dynamicArray;
    return 0;
}
