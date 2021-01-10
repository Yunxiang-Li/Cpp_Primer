# Chapter 10. Generic Algorithms

## Exercise 10.1

**The algorithm header defines a function named count that, like find, takes a pair of iterators and a value. count returns a count of how often that value appears. Read a sequence of ints into a vector and print the count of how many elements have a given value.**

[10.1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.1%20Solution.cpp)

## Exercise 10.2

**Repeat the previous program, but read values into a list of strings.**

[10.2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.2%20Solution.cpp)

## Exercise 10.3

**Use accumulate to sum the elements in a `vector<int>`.**

[10.3 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.3%20Solution.cpp)

## Exercise 10.4

**Assuming v is a `vector<double>`, what, if anything, is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?**

The result of `accumulate(v.cbegin(), v.cend(), 0)` will be converted into a interger instead of a double since the third argument `0` is an integer and `accumulate` function will return the result with the exact same type as the third argument.
