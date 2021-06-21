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

## Exercise 15.7

**Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.**

[15.7 Limit_quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.7%20Limit_quote.hpp)

[15.7 Limit_quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.7%20Limit_quote.cpp)

## Exercise 15.8

**Define static type and dynamic type.**

static type: Static type is known at compile time. Its type is just the same as its declaration.

dynamic type: Type of an object at run time. The dynamic type of an object to which a reference refers or to which a pointer points may differ from the static type of the reference or pointer.

## Exercise 15.9

**When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.**

A pointer or reference to a base-class type can refer to an object of derived type. In such cases the static type is a reference (or pointer) to the base class, but the dynamic type is a reference (or pointer) to the derived class.

## Exercise 15.10

**Recalling the discussion from §8.1 (p. 311), explain how the program on page 317 that passed an `ifstream` to the `Sales_data` read function works.**

the function takes an `istream` parameter which means an `istream` object or an object which derived from `istream` class will work. Because the `ifstream` object is a derived class of `istream` class thus it works.
