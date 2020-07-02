#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::vector;
using std::iterator;

int main()
{
    //Initialize two vector<int> with size 10.
    vector<int> ia(10);
    vector<int> ib(10);

    //Set ia's each element's value to its index.
    for (auto i = ia.begin(); i != ia.end(); i++)
        *i = i - ia.begin();

    //Output ia's each element's value.
    for (auto& element : ia)
        cout << element << ' ';
    cout << '\n';

    //Assign ia's each position's value to ib's each position.
    for (decltype(ib.size()) i = 0; i < ia.size(); i++)
        ib[i] = ia[i];

    //Output ib's each element's value.
    for (auto& element : ia)
        cout << element << ' ';
    cout << '\n';
}












