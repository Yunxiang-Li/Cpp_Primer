# Chapter 13. Copy Control.md

## Exercise 13.1

**What is a copy constructor? When is it used?**

A copy constructor is a constructor which first parameter is a **const reference** to the class type and any additional parameters(if exist) have **default values**.

When copy initialization happens, either the copy constructor or the move constructor is called.

Copy constructor is used when:

- Define variables using an =
- Pass an object as an argument to a parameter of non-reference type
- Return an object from a function that has a non-reference return type
- Brace initialize the elements in an array or the members of an aggregate class
- Some class types also use copy initialization for the objects they allocate.

## Exercise 12.2

**Write your own version of the StrBlob class including the const versions of front and back.**

[12.2 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.2%20Solution.hpp)

[12.2 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.2%20Solution.cpp)
