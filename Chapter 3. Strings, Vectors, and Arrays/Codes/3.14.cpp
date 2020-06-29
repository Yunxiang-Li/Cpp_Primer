#include <iostream>
#include <vector>

using std :: cout;
using std :: cin;
using std :: vector;

int main()
{
    vector<int> vec;
    int i;
    cout << "Please input a sequence of ints" << '\n';

    //Push each integer to the vector.
    while (cin >> i)
        vec.push_back(i);

    return 0;
}
