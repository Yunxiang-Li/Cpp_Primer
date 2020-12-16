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

## Exercise 7.14

**Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.**

```cpp
Sales_data() : units_sold(0) , revenue(0){}
```

## Exercise 7.15

**Add appropriate constructors to your Person class.**

[7.15 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.15%20Solution.hpp)

## Exercise 7.16

**What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?**

There are no constraints on where and how often an access specifier may appear.The specified access level remains in effect until the next access specifier or the end of the class body.

The members which are accessible to all parts of the program should be defined inside a public specifier.

The members which are accessible to the member functions of the class but are not accessible to code that uses the class should be defined inside a private specifier.

## Exercise 7.17

**What, if any, are the differences between using class or struct?**

A class's default access level is private and a struct's default access level is public.

## Exercise 7.18

**What is encapsulation? Why is it useful?**

Encapsulation is the separation of implementation from interface. It hides the implementation details of a type. 

It is useful because:
1. User code cannot inadvertently corrupt the state of an encapsulated object.
2. The implementation of an encapsulated class can change over time without requiring changes in user-level code.

## Exercise 7.19

**Indicate which members of your Person class you would declare as public and which you would declare as private. Explain your choice.**

I will declare `constructors, getName(), getAddress()` as public and declare members `name, address` as private.

I do not want users to have direct access to class members since users may modify each member's value which is not what we want. Instead we will provide appropriate access functions(such as `getName` and `getAddress`) to enable users to get what they want but not modify original values.

## Exercise 7.20

**When are friends useful? Discuss the pros and cons of using friends.**

Pros:

1. Users can use friend functions to access class members without specifying the class name.

2. Users can access all non-public class members easily.

3. Programmers can use friends to help test all private members of the class.

Cons:

1. Decrease codes' encapsulation, maintainability and verbosity.

2. Sometimes it may be a bad idea to let users have opportunities to private class members.
