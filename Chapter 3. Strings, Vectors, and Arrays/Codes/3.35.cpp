#include <iostream>

using std::cin;
using std::cout;
using std::iterator;
using std::begin;
using std::end;

/**
 * Using pointers, write a program to set the elements in an array to zero.
 */
int main()
{
    //Initialize a 10-length array.
    int arr[10];

    //Use pointer to assign each value to zero.
    for (auto ptr = begin(arr); ptr != end(arr); ptr++)
        *ptr = 0;

    //Output each element's value.
    for (auto ptr = begin(arr); ptr != end(arr); ptr++)
        cout << *ptr << ' ';

    return 0;
}












