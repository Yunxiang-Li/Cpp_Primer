#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;

int main()
{
    vector<string> vec;
    string str;
    while (cin >> str)
        vec.push_back(str);

    for (auto it = vec.begin(); it != vec.cend() && !(it -> empty()); it++) {
        for (auto &c : (*it)) {
            c = toupper(c);
        }
        cout << (*it) << '\n';
    }

    return 0;
}
