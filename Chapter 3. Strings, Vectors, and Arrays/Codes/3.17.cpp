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
    string myStr;
    cout << "Please input a sequence of strings" << '\n';

    while (cin >> myStr) {
        if (myStr == "end")
            break;
        else
            vec.push_back(myStr);
    }


    for (auto& str : vec)
        for (auto& letter : str)
            letter = toupper(letter);

    for (decltype(vec.size()) index = 0; index != vec.size(); index++) {
        if (index % 8 == 0 && index != 0)
            cout << '\n';
        cout << vec[index] << ' ';
    }

    return 0;
}
