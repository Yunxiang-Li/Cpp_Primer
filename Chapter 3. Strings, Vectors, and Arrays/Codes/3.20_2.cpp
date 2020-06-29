#include <iostream>
#include <vector>
#include <string>

using std :: cout;
using std :: cin;
using std :: vector;

int main()
{
    vector<int> vec;
    int element;
    cout << "Please input a set of integers" << '\n';

    while (cin >> element)
        vec.push_back(element);

    if (vec.empty()) {
        cout << "No integers input" << '\n';
        return -1;
    }

    else if (vec.size() == 1) {
        cout << "Only one element exists" << '\n';
        cout << "It is " << vec[0] << '\n';
    }

    else {
        for (decltype(vec.size()) i = 0; i < vec.size() / 2; i++) {
            cout << "Sum of this pair of begin and end elements is " << vec[i] + vec[vec.size() - 1 - i] << '\n';
        }
    }

    if (vec.size() % 2 != 0)
        cout << "One middle element left and it is " << vec[vec.size() / 2];

    return 0;
}
