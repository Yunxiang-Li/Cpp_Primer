# Chapter 15. Object-Oriented Programming

## Exercise 15.1

**What is a virtual member?**

A virtual member is a member function in a base class expects its derived class to override and define its own version. Whether to call the member function in base class or in derived class depends on dynamic binding. 

In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 14.2

**Write declarations for the overloaded input, output, addition, and compound-assignment operators for `Sales_data`.**

[14.2 Sales_data Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.2%20Sales_data.hpp)

[14.2 Sales_data Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.2%20Sales_data.cpp)
