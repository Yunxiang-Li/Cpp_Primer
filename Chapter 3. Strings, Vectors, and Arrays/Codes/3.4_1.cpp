#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string strA, strB;

    //Input two strings.
    while (cin >> strA >> strB) {
        //Check if two strings are equal.
        if (strA == strB)
            cout << "Two strings are equal!" << '\n';
        //Check which string is larger.
        else
            cout << "The larger string is " << (strA < strB ? strB : strA) << '\n';
    }

    return 0;
}
