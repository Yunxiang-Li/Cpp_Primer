#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string strCct, strEach;

    while (cin >> strEach) {
        //Separate adjacent input strings by a space
        strCct += strEach + " ";

        //When we press enter to go to a new line, the input process is over.
        if (cin.get() == '\n')
            break;
    }

    cout << "The concatenated string is " << strCct << '\n';

    return 0;
}
