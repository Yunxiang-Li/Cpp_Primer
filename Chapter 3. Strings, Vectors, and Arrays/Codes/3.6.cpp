#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string str ("This is a simple string");

    for (auto &c : str)
        c = 'X';

    cout << "The string after change is " << str << '\n';

    return 0;
}
