# Chapter 7.Classes

## Exercise 7.1

**Write a version of the transaction-processing program from § 1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).**

[Sales_data.h](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%202.%20Variables%20and%20Basic%20Types/Codes/2.42%20Sales_data.h)

[7.1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.1%20Solution.cpp)

## Exercise 7.2

**Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).**

[7.2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.2%20Solution.hpp)

## Exercise 7.3

**Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.**

[7.3 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.3%20Solution.cpp)

## Exercise 7.4

**Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.**

[7.4 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.4%20Solution.cpp)

## Exercise 7.5

**Provide operations in your Person class to return the name and address. Should these functions be const? Explain your choice.**

[7.5 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.5%20Solution.cpp)

## Exercise 7.6

**Define your own versions of the add, read, and print functions.**

[7.6 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.6%20Solution.hpp)

## Exercise 7.7

**Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.**

[7.7 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.7%20Solution.cpp)

## Exercise 7.8

**Why does read define its Sales_data parameter as a plain reference and print define its parameter as a reference to const?**

Define `read`'s `Sales_data` parameter as plain reference since it intended to change the revenue's value.

Define `print`'s `Sales_data` parameter as a reference to const since it did not intend to change any member's value of this object.

## Exercise 7.9

**Add operations to read and print Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).**

[7.9 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.9%20Solution.hpp)

## Exercise 7.10

**What does the condition in the following if statement do?**

```cpp
if (read(read(cin, data1), data2))
```

This line of codes work like this:

```cpp
std::istream &firstIstream = read(cin, data1);
std::istream &secondIstream = read(firstStep, data2);
if (secondIstream)
```

Inner `read` function first reads and stores `data1`'s members into a `std::istream` object. Outer `read` function then reads and stores the `data2`'s memebers into the same `std::istream` object.

The condition of the if statement checks whether the result `std::istream` object is empty or not after trying to read and store `data1` and `data2`'s members.

## Exercise 7.11

**Add constructors to your Sales_data class and write a program to use each of the constructors.**

[7.11 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.11%20Solution.hpp)

[7.11 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.11%20Solution.cpp)

## Exercise 7.12

**Move the definition of the Sales_data constructor that takes an istream into the body of the Sales_data class.**

[7.12 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.12%20Solution.hpp)

## Exercise 7.13

**Rewrite the program from page 255 to use the istream constructor.**

[7.13 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.13%20Solution.cpp)
