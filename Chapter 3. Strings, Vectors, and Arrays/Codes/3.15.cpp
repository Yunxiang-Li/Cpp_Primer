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

    while (cin >> str)
        vec.push_back(str);

    return 0;
}
