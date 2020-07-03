#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    // Compare two strings
    string s1("Hello");
    string s2("World");

    if (s1 == s2)
        cout << "same string." << endl;
    else if (s1 > s2)
        cout << "s1 > s2" << endl;
    else
        cout << "s2 < s1" << endl;

    cout << "=========" << endl;

    return 0;
}
