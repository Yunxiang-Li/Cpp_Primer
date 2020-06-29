#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string str ("This is a simple string");
    
    //Change each char of string to 'X'.
    for (decltype(str.size()) index = 0; index < str.size(); index ++)
        str[index] = 'x';

    cout << "The string after change is " << str << '\n';

    return 0;
}
