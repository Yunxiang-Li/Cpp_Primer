#include <iostream>
#include <vector>
using std::vector;

// Define a vector and give it ten elements in three ways.
int main()
{
    //Specifying size and initializing all values 
    vector<int> ivec1(10, 42);
    
    //List initialization.
    vector<int> ivec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    
    //For loop initialization.
    vector<int> ivec3;
    for (int i = 0; i != 10; ++i) ivec3.push_back(42);
}
