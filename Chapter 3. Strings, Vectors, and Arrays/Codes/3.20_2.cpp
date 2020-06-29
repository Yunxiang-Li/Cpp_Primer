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

    //Prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.
    else {
        for (decltype(vec.size()) i = 0; i < vec.size() / 2; i++) {
            cout << "Sum of this pair of begin and end elements is " << vec[i] + vec[vec.size() - 1 - i] << '\n';
        }
    }

    //If we have odd number of elements, one middle element will be left, output it.
    if (vec.size() % 2 != 0)
        cout << "One middle element left and it is " << vec[vec.size() / 2];

    return 0;
}
