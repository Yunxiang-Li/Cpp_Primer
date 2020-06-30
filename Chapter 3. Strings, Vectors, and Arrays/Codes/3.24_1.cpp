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

    //Check if the vector is empty.
    if (vec.empty()) {
        cout << "No integers input" << '\n';
        return -1;
    }

        //Check if the vector only has one element.
    else if (vec.size() == 1) {
        cout << "Only one element exists" << '\n';
        cout << "It is " << vec[0] << '\n';
    }

        //Print the sum of each pair of adjacent elements
    else {
        for (auto it = vec.begin(); it != vec.end() - 1; it++) {
            cout << "Sum of these two adjacent elements is " << *it + *(it + 1) << '\n';
        }
    }

    return 0;
}
