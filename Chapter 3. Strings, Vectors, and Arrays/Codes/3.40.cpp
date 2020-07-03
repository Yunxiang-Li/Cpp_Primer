#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    //Initialize two character arrays from string literals
    const char str1[] = "Hello";
    const char str2[] = "world!";

    //Define a third character array to hold the concatenation of the two arrays.
    size_t new_size = strlen(str1) + strlen(" ") + strlen(str2) + 1;
    char* str3 = new char[new_size];

    //Use `strcpy` and `strcat` to copy the two arrays into the third.
    strcpy(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);

    std::cout << str3 << std::endl;

    //Delete the str3.
    delete [] str3;
}
