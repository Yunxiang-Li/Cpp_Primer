#include <cstddef>
#include <iostream>

using std::cout;

int main()
{
    //Initialize two arrays with size 10.
    constexpr size_t array_size = 10;
    int ia[array_size];
    int ib[array_size];

    //Set ia's each element's value to its index.
    for (size_t ix = 0; ix < array_size; ++ix)
        ia[ix] = ix;

    //Output ia's each element's value.
    for (auto& element : ia)
        cout << element << ' ';
    cout << '\n';

    //Assign ia's each position's value to ib's each position.
    for (size_t i = 0; i < 10; i++) {
        ib[i] = ia[i];
    }

    //Output ib's each element's value.
    for (auto& element : ib)
        cout << element << ' ';
    cout << '\n';
    
    return 0;
}
