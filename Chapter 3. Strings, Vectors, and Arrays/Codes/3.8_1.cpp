#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string str ("This is a simple string");

    decltype(str.size()) index = 0;

    while (index < str.size()) {
        str[index] = 'x';
        index++;
    }

    cout << "The string after change is " << str << '\n';

    return 0;
}
