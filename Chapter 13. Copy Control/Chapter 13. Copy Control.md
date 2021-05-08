# Chapter 13. Copy Control.md

## Exercise 13.1

**What is a copy constructor? When is it used?**

A copy constructor is a constructor which first parameter is a **const reference** to the class type and any additional parameters(if exist) have **default values**.

When copy initialization happens, either the copy constructor or the move constructor is called.

Copy constructor is used when:

- Define variables using an `=`
- Pass an object as an argument to a parameter of non-reference type
- Return an object from a function that has a non-reference return type
- Brace initialize the elements in an array or the members of an aggregate class
- Some class types also use copy initialization for the objects they allocate.

## Exercise 13.2

**Explain why the following declaration is illegal:**

```cpp
Sales_data::Sales_data(Sales_data rhs);
```

If the copy constructor declaration is like this, the call would never succeed to call the copy constructor, `Sales_data rhs` is a non-reference argument to a parameter, thus, we'd need to use the copy constructor of class `Sales_data` to copy the argument, which we'd need to call the copy constructor again, and so on indefinitely.

[12.2 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.2%20Solution.hpp)

[12.2 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.2%20Solution.cpp)
