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
        //When user input "end", break the loop
        if (myStr == "end")
            break;
        else
            //Push each string to the vector.
            vec.push_back(myStr);
    }

    //For each string in the vector
    for (auto& str : vec)
        //For each char in each string
        for (auto& letter : str)
            //Change each char to its uppercase form.
            letter = toupper(letter);

    //Print the transformed elements, eight words to a line.
    for (decltype(vec.size()) index = 0; index != vec.size(); index++) {
        if (index % 8 == 0 && index != 0)
            cout << '\n';
        cout << vec[index] << ' ';
    }

    return 0;
}
