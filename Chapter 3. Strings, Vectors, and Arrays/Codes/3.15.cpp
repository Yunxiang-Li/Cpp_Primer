#include <iostream>
#include <vector>
#include <string>

using std :: cout;
using std :: cin;
using std :: vector;
using std :: string;

int main()
{
    vector<string> vec;
    string str;
    cout << "Please input a sequence of strings" << '\n';

    //Push each string to the vector.
    while (cin >> str) {
        //When user input "end", break the loop.
        if (str == "end")
            break;
        vec.push_back(str);
    }
    return 0;
}
