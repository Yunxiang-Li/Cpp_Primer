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

    //For each line of string
    while (getline(cin, str)) {
        //For each char of the string
        for (auto c : str)
            //Ouput if it is not a punctuation.
            if (!ispunct(c))
                cout << c ;
        cout << '\n';
    }

    return 0;
}
