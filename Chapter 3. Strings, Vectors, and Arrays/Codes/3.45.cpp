#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // Use a range for to manage the iteration
    // Use auto
    for (auto& p : ia)
        for (auto& q : p)
            cout << q << " ";
    cout << endl;

    // Use ordinary for loop using subscripts
    // Use auto
    for (auto i = 0; i != 3; ++i)
        for (auto j = 0; j != 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // Use pointers.
    // Use auto
    for (auto p = ia; p != ia + 3; ++p)
        for (int* q = *p; q != *p + 4; ++q) cout << *q << " ";
    cout << endl;

    return 0;
}
