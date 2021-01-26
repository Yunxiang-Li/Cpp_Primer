# Chapter 11. Associative Containers

## Exercise 11.1

**Describe the differences between a map and a vector.**

A `map` is an associative container of key-value pairs. Each value is bound to a key thus we can get a value by its key.

A `vector` is a sequential container of objects and every object has an associated index thus we can have access to each object by its index.

## Exercise 11.2

**Give an example of when each of list, vector, deque, map, and set might be most useful.**

`list` : When we need to insert or delete elements from any positions occasionally.

`vector` : When we want all elements to be stored at contiguous memory location.

`deque` : When we need efficient insertion/removal at the beginning and the end of the sequence and random access.

`map` : When we need to store key-value pairs, such as a dictionary.

`set` : When we need a collection of certain objects(for instance, to store items that we do not want).

## Exercise 11.3

**Write your own version of the word-counting program.**

[11.3 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.3%20Solution.cpp)

## Exercise 11.4

**Extend your program to ignore case and punctuation. For example, “example.” “example,” and “Example” should all increment the same counter.**

[11.4 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.4%20Solution.cpp)

## Exercise 11.5

**Explain the difference between a map and a set. When might you use one or the other?**

`set` : Only store one type of elements as keys.

`map` : Store key-value pairs such as {key, value} and each value is bound to a key.

Use `set` when we only need to store one type of elements and `map` when we need to store key-value pairs.

## Exercise 11.6

**Explain the difference between a set and a list. When might you use one or the other?**

`set`'s elements are unique and in order, but `list` is neither.

Use `list` when we need to insert or delete elements from any positions occasionally.

Use `set` when we need to store one type of elements.

## Exercise 11.7

**Define a map for which the key is the family’s last name and the value is a vector of the children’s names. Write code to add new families and to add new children to an existing family.**

[11.7 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.7%20Solution.cpp)

## Exercise 11.8

**Write a program that stores the excluded words in a vector instead of in a set. What are the advantages to using a set?**

[11.8 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.8%20Solution.cpp)

Advantages:

1. All elements in a `set` are ordered specifically. However, elements in a `vector` are only stored by the adding order.

2. Insert an element into a `vector` cost more time than a `set`.

## Exercise 11.9

**Define a map that associates words with a list of line numbers on which the word might occur.**

```cpp
std::map<std::string, std::list<unsigned>> myMap;
```

## Exercise 11.10

**Could we define a map from `vector<int>::iterator` to int? What about from `list<int>::iterator` to int? In each case, if not, why not?**

We can define a map from `vector<int>::iterator` to int because iterators of `std::vector` are random access iterators thus they can be compared by `<` operator.

However, we cannot define a map from `list<int>::iterator` to int because iterators of `std::list` are bidirectional iterators thus they cannot be compared by `<` operator.

## Exercise 11.11

**Redefine bookstore without using decltype.**

[11.11 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.11%20Solution.cpp)

## Exercise 11.12

**Write a program to read a sequence of strings and ints, storing each into a pair. Store the pairs in a vector.**

[11.12 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.12%20Solution.cpp)

## Exercise 11.13

**There are at least three ways to create the pairs in the program for the previous exercise. Write three versions of that program, creating the pairs in each way. Explain which form you think is easiest to write and understand, and why.**

[11.13 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.13%20Solution.cpp)

I think `vec.emplace_back(str, i);` is the easiest way to write and understand since it does not require us to use `std::pair` or braced initializer list directly.

## Exercise 11.14

**Extend the map of children to their family name that you wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a pair that holds a child’s name and birthday.**

[11.14 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.14%20Solution.cpp)

## Exercise 11.15

**What are the mapped_type, key_type, and value_type of a map from int to` vector<int>`?**

Mapped_type of `std::map<int, std::vector<int>>` is `std::vector<int>`.

Key_type of `std::map<int, std::vector<int>>` is `int`.

Value_type of `std::map<int, std::vector<int>>` is `std::pair<const int, std::vector<int>>`.

## Exercise 11.16

**Using a map iterator write an expression that assigns a value to an element.**

```cpp
std::map<int, const std::string> myMap;
myMap[5] = "Hello";
myMap[20] = "Word";
std::map<int, const std::string>::iterator iter = myMap.begin();
iter -> second = "hello";
```

## Exercise 11.17

**Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. Indicate whether each call is legal:**

```cpp
// Legal, calls c's insert function.
copy(v.begin(), v.end(), inserter(c, c.end())); 

// Illegal since c does not have push_back function. 
copy(v.begin(), v.end(), back_inserter(c));

// Legal, calls v's insert function.
copy(c.begin(), c.end(), inserter(v, v.end()));

// Legal, calls v's push_back function.
copy(c.begin(), c.end(), back_inserter(v));
```

## Exercise 11.18

**Write the type of map_it from the loop on page 430 without using auto or decltype.**

type of map_it is:

```cpp
std::map<std::string, size_t>::iterator
```

## Exercise 11.19

**Define a variable that you initialize by calling begin() on the multiset named bookstore from § 11.2.2 (p. 425). Write the variable’s type without using auto or decltype.**

```cpp
using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
std::multiset<Sales_data, compareType> bookstore(compareIsbn);
std::multiset<Sales_data, compareType>::iterator map_iter = bookstore.begin();
```
