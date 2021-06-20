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

## Exercise 15.4

**Which of the following declarations, if any, are incorrect? Explain why.**

```cpp
class Base { ... };
(a) class Derived : public Derived { ... }; // Incorrect, a class cannot inherit itself.
(b) class Derived : private Base { ... }; // Correct.
// Incorrect, a derived class is declared like any other class. The declaration should only contain the class name.
(c) class Derived : public Base; 
```

## Exercise 15.5

**Define your own version of the `Bulk_quote` class.**

`Quote` class is same as exercise 15.3.

[15.5 Bulk_quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.5%20Bulk_quote.hpp)

[15.5 Bulk_quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.5%20Bulk_quote.cpp)

## Exercise 15.6

**Test your `print_total` function from the exercises in § 15.2.1 (p. 595) by passing both `Quote` and `Bulk_quote` objects on that function.**

[15.6 Test](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.6%20main.cpp)
