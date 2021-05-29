# Chapter 14. Overloaded Operations and Conversions

## Exercise 14.1

**In what ways does an overloaded operator differ from a built-in operator? In what ways are overloaded operators the same as the built-in operators?**

Different:

1. We can call an overloaded operator function directly.
2. An overloaded operator function must either be a member of a class or have at least one parameter of class type.
3. A few operators(`AND`, `OR`, `,`, `&&`, `||`) guarantee the order in which operands are evaluated. Overloaded versions of these operators do not preserve order of evaluation and/or short-circuit evaluation, it is usually a bad idea to overload them.

Same:

1. Overloaded operators have same precedence and associativity as the corresponding built-in operator.

## Exercise 14.2

**Write declarations for the overloaded input, output, addition, and compound-assignment operators for `Sales_data`.**

[14.2 Sales_data Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.2%20Sales_data.hpp)

[14.2 Sales_data Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.2%20Sales_data.cpp)
