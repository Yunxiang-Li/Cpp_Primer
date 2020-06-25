#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string strA, strB;

    while (cin >> strA >> strB) {
        if (strA.size() == strB.size())
            cout << "Two strings have same size" << '\n';
        else
            cout << "The string which has larger size is " << (strA.size() < strB.size() ? strB : strA) << '\n';
    }

    return 0;
}
