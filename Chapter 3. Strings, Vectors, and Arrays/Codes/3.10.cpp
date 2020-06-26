#include <iostream>
#include <string>
#include <cctype>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string str;

    cout << "Please input a string of characters with punctuations!" << '\n';

    while (getline(cin, str)) {
        for (auto c : str)
            if (!ispunct(c))
                cout << c ;
        cout << '\n';
    }

    return 0;
}
