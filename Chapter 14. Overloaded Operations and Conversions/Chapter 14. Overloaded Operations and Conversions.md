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

`StrVec`: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20StrVec.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20StrVec.cpp)

`String`: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20String.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.16%20String.cpp)

## Exercise 14.17

**Should the class you chose for exercise 7.40 from § 7.5.1(p. 291) define the equality operators? If so, implement them. If not, explain why not.**

Same as exercise 14.15.

## Exercise 14.18

**Define relational operators for your `StrBlob`(§ 12.1.1, p. 456), `StrBlobPtr` (§ 12.1.6, p. 474), `StrVec` (§ 13.5, p.526), and `String` (§ 13.5, p. 531) classes.**

`StrBlob` and `ConstStrBlobPtr`: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.18%20StrBlob.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.18%20StrBlob.cpp)

`StrVec`: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.18%20StrVec.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.18%20StrVec.cpp)

`String`: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.18%20String.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.18%20String.cpp)

## Exercise 14.19

**Should the class you chose for exercise 7.40 from § 7.5.1(p. 291) define the relational operators? If so, implement them. If not, explain why not.**

Same as exercise 14.15.

## Exercise 14.20

**Define the addition and compound-assignment operators for your `Sales_data` class.**

Same as exercise 14.2.

## Exercise 14.21

**Write the `Sales_data` operators so that `+` does the actual addition and `+=` calls `+`. Discuss the disadvantages of this approach compared to the way these operators were defined in § 14.3 (p. 560) and § 14.4 (p. 564).**

Instead of exercise 14.2

```cpp
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    Sales_data old_data = *this;
    *this = old_data + rhs;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}
```

Disadvantage: For both functions, we have to use a temporary `Sales_data` object to store the intermediate value which is not very efficient.

## Exercise 14.22

**Define a version of the assignment operator that can assign a `string` representing an ISBN to a `Sales_data`.**

[14.22 Sales_data Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.22%20Sales_data.hpp)

[14.22 Sales_data Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.22%20Sales_data.cpp)

## Exercise 14.23

**Define an `initializer_list` assignment operator for your version of the `StrVec` class.**

[14.23 StrVec Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.23%20StrVec.hpp)

[14.23 StrVec Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.23%20StrVec.cpp)

## Exercise 14.24

**Decide whether the class you used in exercise 7.40 from §7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define those operators.**

[14.24 Date Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.24%20Date.hpp)

[14.24 Date Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.24%20Date.cpp)


## Exercise 14.25

**Implement any other assignment operators your class should define. Explain which types should be used as operands and why.**

Same as exercise 14.24.

## Exercise 14.26

**Define subscript operators for your `StrVec`, `String`, `StrBlob`, and `StrBlobPtr` classes.**

`StrBlob` and `ConstStrBlobPtr`: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.26%20StrBlob.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.26%20StrBlob.cpp)

`StrVec`: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.26%20StrVec.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.26%20StrVec.cpp)

`String`: [Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.26%20String.hpp) | [Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.26%20String.cpp)

## Exercise 14.27

**Add increment and decrement operators to your `StrBlobPtr` class.**

[14.27 StrBlobPtr Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.27%20StrBlob.hpp)

[14.27 StrBlobPtr Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.27%20StrBlob.cpp)

## Exercise 14.28

**Define addition and subtraction for `StrBlobPtr` so that these operators implement pointer arithmetic (§ 3.5.3, p. 119).**

[14.28 StrBlobPtr Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.28%20StrBlob.hpp)

[14.28 StrBlobPtr Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.28%20StrBlob.cpp)

## Exercise 14.29

**We did not define a `const` version of the increment and decrement operators. Why not?**

Because `++` and `--` operators will change the state of the object thus we cannot define `const` versions of the increment and decrement operators.

## Exercise 14.30

**Add dereference and arrow operators to your `StrBlobPtr` class and to the `ConstStrBlobPtr` class that you defined in exercise 12.22 from § 12.1.6 (p. 476). Note that the operators in `constStrBlobPtr` must return `const` references because the data member in `constStrBlobPtr` points to a `const vector`.**

[14.30 StrBlobPtr Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.30%20StrBlob.hpp)

[14.30 StrBlobPtr Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.30%20StrBlob.cpp)

## Exercise 14.31

**Our `StrBlobPtr` class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?**

We do not need to handle any dynamic allocation thus synthesized copy constructor/assignment operator/destructor is enough.

## Exercise 14.32

**Define a class that holds a pointer to a `StrBlobPtr`. Define the overloaded arrow operator for that class.**

[14.31 StrBlobPtrContainer Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.31%20StrBlobPtrContainer.hpp)

[14.31 StrBlobPtrContainer Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.31%20StrBlobPtrContainer.cpp)

## Exercise 14.33

**How many operands may an overloaded function-call operator take?**

An overloaded operator function has the same requirement as the normal function opeator. Therefore value can be from 0 to 256.

## Exercise 14.34

**Define a function-object class to perform an if-then-else operation: The call operator for this class should take three parameters. It should test its first parameter and if that test succeeds, it should return its second parameter; otherwise, it should return its third parameter.**

```cpp
struct FunctionObject {
    int operator()(bool b, int iA, int iB) {
        return b ? iA : iB;
    }
};
```

## Exercise 14.35

**Write a class like `PrintString` that reads a line of input from an `istream` and returns a `string` representing what was read. If the read fails, return the empty `string`.**

[14.35 ReadStr Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.35%20ReadStr.hpp)

[14.35 ReadStr Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.35%20ReadStr.cpp)

[14.35 main](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2014.%20Overloaded%20Operations%20and%20Conversions/Codes/14.35%20main.cpp)
