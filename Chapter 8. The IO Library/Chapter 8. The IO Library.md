# Chapter 8. The IO Library

## Exercise 8.1

**Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.**

[8.1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.1%20Solution.cpp)

## Exercise 8.2

**Test your function by calling it, passing cin as an argument.**

[8.2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.2%20Solution.cpp)

## Exercise 8.3

**What causes the following while to terminate?**

```cpp
while (cin >> i) /*  ...    */
```

When at least one of `cin` 's error state flag is set (such as `eofbit`, `failbit` and `badbit`).

## Exercise 8.4

**Write a function to open a file for input and read its contents into a vector of strings, storing each line as a separate element in the vector.**

[8.4 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.4%20Solution.cpp)
