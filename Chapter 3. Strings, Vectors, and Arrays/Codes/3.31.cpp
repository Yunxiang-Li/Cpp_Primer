#include <cstddef>
#include <iostream>

using std::cout;

int main()
{
    //Initialize an 10-length array ia.
    constexpr size_t array_size = 10;
    int ia[array_size];

    //Set each element's value equals to its index;
    for (size_t ix = 0; ix < array_size; ++ix)
        ia[ix] = ix;

    //Output each element's value.
    for (auto& element : ia)
        cout << element << ' ';
    cout << '\n';
}
