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

(e) `<<`: If member operator then relative class must have to be members of `ostream`. However, we cannot add members to `std::ostream` class. Therefore non-member operator.

(f) `&&`: symmetric operator thus non-member operator. We should normally avoid overloading `&&` operator.

(g) `==`: symmetric operator thus non-member operator. 

(h) `()`: must be member operator.

## Exercise 14.5

**In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of one of the following classes. Decide what, if any, overloaded operators your class should provide.**

(a) Book

(b) Date

(c) Employee

(d) Vehicle

(e) Object

(f) Tree

For instance, for `Book` class, `==` and `!=` operators should be overloaded at least. We may also want to overload `>>` and `<<` operators.

## Exercise 14.6

**Define an output operator for your `Sales_data` class.**

Same as exercise 14.2.

## Exercise 14.7

**Define an output operator for you `String` class you wrote for the exercises in § 13.5 (p. 531).**

[14.7 String Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.7%20String.hpp)

[14.7 String Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.7%20String.cpp)

## Exercise 14.8

**Define an output operator for the class you chose in exercise 7.40 from § 7.5.1 (p. 291).**

[14.8 Book Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.8%20Book.hpp)

[14.8 Book Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.8%20Book.cpp)

## Exercise 14.9

**Define an input operator for your `Sales_data` class.**

Same as exercise 14.2.

## Exercise 14.10

**Describe the behavior of the `Sales_data` input operator if given the following input:**

(a) 0-201-99999-9 10 24.95

(b) 10 24.95 0-210-99999-9

Result:

(a) correct format.

(b) illegal input.

## Exercise 14.11

**What, if anything, is wrong with the following `Sales_data` input operator? What would happen if we gave this operator the data in the previous exercise?**

```cpp
istream& operator>>(istream& in, Sales_data& s)
{
  double price;
  in >> s.bookNo >> s.units_sold >> price;
  s.revenue = s.units_sold * price;
  return in;
}
```

Codes above do not have any input checks thus when user input is in wrong format, there will be no warnings and may cause issues.

## Exercise 14.12

**Define an input operator for the class you used in exercise 7.40 from § 7.5.1 (p. 291). Be sure the operator handles input errors.**

Same as exercise 14.8.

## Exercise 14.13

**Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think `Sales_data` ought to support? Define any you think the class should include.**

I think operator `+` and compound assignment `+=` are already enough.

## Exercise 14.14

**Why do you think it is more efficient to define `operator+` to call `operator+=` rather than the other way around?**

If we instead call `operator+` to help us define `opeator+=`, then we have to use an unnecessary temporary object as in the `operator+`'s example above.

## Exercise 14.15

**Should the class you chose for exercise 7.40 from § 7.5.1(p. 291) define any of the arithmetic operators? If so, implement them. If not, explain why not.**

[14.15 Book Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.15%20Book.hpp)

[14.15 Book Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.15%20Book.cpp)

## Exercise 14.16

**Define equality and inequality operators for your `StrBlob`(§ 12.1.1, p. 456), `StrBlobPtr` (§ 12.1.6, p. 474), `StrVec` (§ 13.5, p.526), and `String` (§ 13.5, p. 531) classes.**

`StrBlob` and `ConstStrBlobPtr`: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20StrBlob.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20StrBlob.cpp)

StrVec: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20StrVec.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20StrVec.cpp)

String: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20String.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20String.cpp)
