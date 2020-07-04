#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    //Initialize a vector of ints.
    vector<int> vec{1,2,3,4,5};

    //Initialize an array.
    int a[5];

    //Set array's each element's value from the vector.
    for (auto i = begin(a); i != end(a); i++)
        *i = vec[i - begin(a)];

    //Output each element's value of the array
    for (auto& element : a)
        cout << element << ' ';
    cout << '\n';

    return 0;
}
