#include <iostream>
#include <string>

using std :: cout;
using std :: cin;
using std :: endl;
using std :: getline;
using std :: string;


int main()
{
    string line;
    
    while (getline(cin, line)) {
        cout << line << '\n';
    }

    return 0;
}
