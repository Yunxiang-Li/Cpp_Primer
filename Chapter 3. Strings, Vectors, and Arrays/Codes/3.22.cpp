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
    while (cin >> str) {
        //When user input end which means the first paragraph ends, break the loop.
        if (str == "end")
            break;
        vec.push_back(str);
    }


    //Change elements in text that correspond to the first paragraph to all uppercase.
    for (auto it = vec.begin(); it != vec.cend() && !(it -> empty()); it++) {
        for (auto &c : (*it)) {
            c = toupper(c);
        }
        
        //Print the content.
        cout << (*it) << ' ';
    }

    return 0;
}
