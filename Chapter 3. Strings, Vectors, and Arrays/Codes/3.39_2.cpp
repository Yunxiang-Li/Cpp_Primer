#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main()
{
    
    // Compare two C-Style character strings.
    const char* cs1 = "Hello";
    const char* cs2 = "World";

    // Use strcmp function.
    auto result = strcmp(cs1, cs2);
    
    if (result == 0)
        cout << "same string." << endl;
    else if (result < 0)
        cout << "s1 < s2" << endl;
    else
        cout << "s2 > s1" << endl;

    return 0;
}
