#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: getline;
using std :: string;


int main()
{
    string line;
    
    //Output one line at a time
    while (getline(cin, line)) {
        cout << line << '\n';
    }

    return 0;
}
