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

## Exercise 8.5

**Rewrite the previous program to store each word in a separate element.**

[8.5 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.5%20Solution.cpp)

## Exercise 8.6

**Rewrite the bookstore program from § 7.1.1 (p. 256) to read its transactions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218).**

[8.6 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.6%20Solution.cpp)

## Exercise 8.7

**Revise the bookstore program from the previous section to write its output to a file. Pass the name of that file as a second argument to main.**

[8.7 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.7%20Solution.cpp)

## Exercise 8.8

**Revise the program from the previous exercise to append its output to its given file. Run the program on the same output file at least twice to ensure that the data are preserved.**

[8.8 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.8%20Solution.cpp)

## Exercise 8.9

**Use the function you wrote for the first exercise in § 8.1.2 (p. 314) to print the contents of an istringstream object.**

[8.9 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.9%20Solution.cpp)

## Exercise 8.10

**Write a program to store each line from a file in a vector<string>. Now use an istringstream to read each element from the vector a word at a time.**

[8.10 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.10%20Solution.cpp)

## Exercise 8.11

**The program in this section defined its istringstream object inside the outer while loop. What changes would you need to make if record were defined outside that loop? Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.**

[8.11 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.11%20Solution.cpp)

## Exercise 8.12

**Why didn’t we use in-class initializers in PersonInfo?**

Because we always need to get data from the input file thus there is no need for us to initialize the `PersonInfo` struct on our own.

## Exercise 8.13

**Rewrite the phone number program from this section to read from a named file rather than from cin.**

[8.13 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%208.%20The%20IO%20Library/Codes/8.13%20Solution.cpp)

## Exercise 8.14

**Why did we declare entry and nums as const auto &?**

Beacause we want to use `entry` and `num` by reference instead of by copy which can be more efficient. However, we do not want to change `entry` or `num` thus we use const reference.
