#include <iostream>
#include <cstddef>
#include <vector>

using std::vector;
using std::cout;
using std::begin;
using std::end;
using std::min;

/**
 * Compare two vectors for equality
 */
int main()
{
    //Initialize two vector<int> objects.
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b{1, 2, 3, 4, 5, 6};

    //Find the smaller size.
    int smallerIndex = min(a.size(), b.size());

    //Compare each value which is less than or equal to the smallerIndex value.
    for (decltype(a.size()) i = 0; i != smallerIndex; i++) {
        if (a[i] < b[i]) {
            cout << "Vector a is smaller than vector b" << '\n';
            break;
        }

        else if (a[i] > b[i]) {
            cout << "Vector a is bigger than vector b" << '\n';
            break;
        }
    }

    //Check which vector is larger, the larger one vector is larger.
    if (a.size() == b.size())
        cout << "Vector a is equal to vector b" << '\n';
    else if (a.size() != smallerIndex)
        cout << "Vector a is bigger than vector b" << '\n';
    else
        cout << "Vector a is smaller than vector b" << '\n';

    return 0;
}
