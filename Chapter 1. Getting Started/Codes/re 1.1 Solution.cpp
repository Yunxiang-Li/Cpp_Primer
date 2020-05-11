#include <iostream>

/**
 * Output integers between lower and higher(both inclusive).
 */
void output(int lower, int higher) {

    for (int i = lower; lower <= higher; lower++) 
        std::cout << lower << std::endl;
}

int main()
{
    int lower, higher = 0;
    std::cout << "Please input two integers: " << std::endl;
    std::cin >> lower >> higher;

    //Always set lower smaller or equal to higher
    if (lower <= higher)
        output(lower, higher);
    else
        output(higher, lower);
}
