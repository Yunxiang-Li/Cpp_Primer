#include <cstddef>
#include <iostream>

using std::cout;

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    int ib[array_size];

    for (size_t ix = 0; ix < array_size; ++ix)
        ia[ix] = ix;

    for (auto& element : ia)
        cout << element << ' ';
    cout << '\n';

    for (size_t i = 0; i < 10; i++) {
        ib[i] = ia[i];
    }

    for (auto& element : ib)
        cout << element << ' ';
    cout << '\n';
}
