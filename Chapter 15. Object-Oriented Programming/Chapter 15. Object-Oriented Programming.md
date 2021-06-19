# Chapter 15. Object-Oriented Programming

## Exercise 15.1

**What is a virtual member?**

A virtual member is a member function in a base class expects its derived class to override and define its own version. Whether to call the member function in base class or in derived class depends on dynamic binding. 

In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 15.2

**How does the protected access specifier differ from private?**

base class members:

`private`: Only base class itself and its friends can access.
`protected`: Base class itself, its friends and all derived classes can access.

## Exercise 15.3

**Define your own versions of the `Quote` class and the `print_total` function.**

[15.3 Quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.3%20Quote.hpp)

[15.3 Quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.3%20Quote.cpp)
