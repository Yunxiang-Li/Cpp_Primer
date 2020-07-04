#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    //Initialize an array.
    int a[5]{1,2,3,4,5};

    //Initialize a vector from an array of ints
    vector<int> vec(begin(a), end(a));

    //Output each element's value from the vector using iterator.
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it <<' ';

    }

    cout << '\n';

    return 0;
}
