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
        //Check if two strings have same length.
        if (strA.size() == strB.size())
            cout << "Two strings have same size" << '\n';
        //Check which string has larger size.
        else
            cout << "The string which has larger size is " << (strA.size() < strB.size() ? strB : strA) << '\n';
    }

    return 0;
}
