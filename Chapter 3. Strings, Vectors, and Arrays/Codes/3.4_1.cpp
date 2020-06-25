#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string strA, strB;

    while (cin >> strA >> strB) {
        if (strA == strB)
            cout << "Two strings are equal!" << '\n';
        else
            cout << "The larger string is " << (strA < strB ? strB : strA) << '\n';
    }

    return 0;
}
