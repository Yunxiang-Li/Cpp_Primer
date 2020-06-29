#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;

int main()
{
    vector<int> vec(10);
    int value = 1;

    //Initialize the vec as {1,2,3,4,5,6,7,8,9,10}.
    for (auto it = vec.begin(); it != vec.cend(); it++) {
        *it = value;
        value++;
    }

    //Assign each element a value that is twice its current value.
    for (auto it = vec.begin(); it != vec.cend(); it++)
        *it *= 2;

    //Output all elements of the vec, it should be {2,4,6,8,10,12,14,16,18,20}.
    for (auto it = vec.begin(); it != vec.cend(); it++)
        cout << *it << ' ';

    return 0;
}
