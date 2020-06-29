#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: string;


int main()
{
    string word;

    //Output one word at a time.
    while (cin >> word) {
        cout << word << '\n';
    }

    return 0;
}
