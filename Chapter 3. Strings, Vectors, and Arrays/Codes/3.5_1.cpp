#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string strCct, strEach;

    //Concatenating what is read into one large string
    while (cin >> strEach) {
        strCct += strEach;

        //When we press enter to go to a new line, the input process is over.
        if (cin.get() == '\n')
            break;
    }

    cout << "The concatenated string is " << strCct << '\n';

    return 0;
}
