#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;

int main()
{
    //Since scores are all >= 0, we use unsigned here.
    vector<unsigned> scores(11, 0);

    unsigned grade;

    //Increment the relative cluster according to the value of the input score.
    while (cin >> grade)
        if (grade <= 100)
            ++(*(scores.begin() + grade / 10));

    //Output each value.
    for (auto score : scores)
        cout << score << " ";

    return 0;
}
