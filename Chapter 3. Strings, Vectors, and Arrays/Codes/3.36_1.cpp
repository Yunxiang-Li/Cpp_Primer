#include <iostream>
#include <cstddef>

using std::cin;
using std::cout;
using std::iterator;
using std::begin;
using std::end;
using std::min;

/**
 * Compare two arrays for equality
 */
int main()
{
    //Initialize two array.
    int a[5]{1,2,3,4,5};
    int b[6]{1,2,3,4,5,6};

    //Get both arrays' size.
    int aLength = sizeof(a) / sizeof(*a);
    int bLength = sizeof(b) / sizeof(*b);

    //Find the smaller size.
    int smallerIndex = min(aLength, bLength);

    //Compare each value which is less than or equal to the smallerIndex value.
    for (size_t i = 0; i != smallerIndex; i++) {
        if (a[i] < b[i]) {
            cout << "Array a is smaller than array b" << '\n';
            break;
        }

        else if (a[i] > b[i]) {
            cout << "Array a is bigger than array b" << '\n';
            break;
        }
    }

    //Check which array is larger, the larger one array is larger.
    if (aLength == bLength)
        cout << "Array a is equal to array b" << '\n';
    else if (aLength != smallerIndex)
        cout << "Array a is bigger than array b" << '\n';
    else
        cout << "Array a is smaller than array b" << '\n';

    return 0;
}












