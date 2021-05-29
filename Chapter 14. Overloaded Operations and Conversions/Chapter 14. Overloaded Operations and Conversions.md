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

## Exercise 14.3

**Both `string` and `vector` define an overloaded `==` that can be used to compare objects of those types. Assuming `svec1` and `svec2` are `vector`s that hold `string`s, identify which version of `==` is applied in each of the following expressions:**

(a) "cobble" == "stone"

(b) svec1[0] == svec2[0]

(c) svec1 == svec2

(d) "svec1[0] == "stone"

Solution:

(a) Use built-in verison of `==` operator here.

(b) `string` version `==`

(c) `vector` version of `==`

(d) `string` version `==`

## Exercise 14.4

**Explain how to decide whether the following should be class members:**

Solution:

(a) `%`: symmetric operator thus non-member operator.

(b) `%=`: changing state of objects thus member operator.

(c) `++`: changing state of objects thus member operator.

(d) `->`: must be member operator.

(e) `<<`: non-member operator is a better choice since we're not allowed to modify ostream.

(f) `&&`: symmetric operator thus non-member operator. We should normally avoid overloading `&&` operator.

(g) `==`: symmetric operator thus non-member operator. 

(h) `()`: must be member operator.
