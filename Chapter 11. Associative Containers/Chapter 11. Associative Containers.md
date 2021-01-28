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

## Exercise 11.20

**Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead of subscripting. Which program do you think is easier to write and read? Explain your reasoning.**

[11.20 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.20%20Solution.cpp)

I think the subscripting way is easier to understand.

## Exercise 11.21

**Assuming word_count is a map from string to size_t and word is a string, explain the following loop:**

```cpp
while (cin >> word)  
  ++word_count.insert({word, 0}).first->second;
```

First insert a new `std::pair` {word, 0} into the `word_count` map, then `word_count.insert({word, 0})` return a `std::pair` with its member `pair::first` set to an iterator pointing to either the newly inserted element `word` or to the element with an equivalent key in the map. The `pair::second` element in the pair is set to true if a new element was inserted or false if an equivalent key already existed. Then we dereference the `pair::first` iterator and access the mapped value of size_t type and increment this value by one.

When insert a new word, a new `std::pair` {word, 0} will be added to the map and just then the counter will be increased by one(actually {word, 1} for each new added word). When a word is already in the map then we just increase its counter by one.

## Exercise 11.22

**Given a `map<string, vector<int>>`, write the types used as an argument and as the return value for the version of insert that inserts one element.**

Argument type: `std::pair<std::string, std::vector<int>>`

Return value type: `std::pair<std::map<std::string, std::vector<int>>::iterator, bool>`

## Exercise 11.23

**Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises in § 11.2.1 (p. 424) to use a multimap.**

[11.23 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.23%20Solution.cpp)

## Exercise 11.24

**What does the following program do?**

```cpp
map<int, int> m;
m[0] = 1;
```

Initialize an empty `std::map<int, int> m`, create a new key with value `0` and set mapped_value associated with the key `0` with value `1`.

## Exercise 11.25

**Contrast the following program with the one in the previous exercise**

```cpp
vector<int> v;
v[0] = 1;
```

`v` is an empty vector thus we cannot read or write by using subscript operator like `v[0]`.

## Exercise 11.26

**What type can be used to subscript a map? What type does the subscript operator return? Give a concrete example—that is, define a map and then write the types that can be used to subscript the map and the type that would be returned from the subscript operator.**

[11.26 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.26%20Solution.cpp)

In my program, the type which can be used to subscript the map is `int`, the type which the subscript operator returns is `std::string`.

## Exercise 11.27

**What kinds of problems would you use count to solve? When might you use find instead?**

I would use `count` to solve problems such like finding all values with a specific key in `std::multimap` or `std::multiset`.
I might use `find` instead when dealing with same question but in `std::map` or `std::set`.

## Exercise 11.28

**Define and initialize a variable to hold the result of calling find on a map from string to vector of int.**

```cpp
std::map<std::string, std::vector<int>>::iterator map_iter = std::map<std::string, std::vector<int>> myMap;
```

## Exercise 11.29

**What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not in the container?**

The `lower_bound` and `upper_bound` will return equal iterators and both will refer to the point where the key can be inserted without disrupting the original order.

`equal_range` will return a `std::pair` where `pair::first` is equivalent to the result of `lower_bound` and `pair::second` is equivalent to the result of `upper_bound`.

## Exercise 11.30

**Explain the meaning of the operand pos.first->second used in the output expression of the final program in this section.**

`pos.first` represents the iteraor which refers to the first element with the matching key we want. and `-> second` part first deference this iterator and then access its second member which is the value we want to print.

## Exercise 11.31

**Write a program that defines a multimap of authors and their works. Use find to find an element in the multimap and erase that element. Be sure your program works correctly if the element you look for is not in the map.**

[11.31 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.31%20Solution.cpp)

## Exercise 11.32

**Using the multimap from the previous exercise, write a program to print the list of authors and their works alphabetically.**

[11.32 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.32%20Solution.cpp)

## Exercise 11.33

**Implement your own version of the word-transformation program.**

[11.33 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.33%20Solution.cpp)

## Exercise 11.34

**What would happen if we used the subscript operator instead of find in the transform function?**

This is illegal and will cause error. Using subscript operator instead of `find` in the `transform` function will insert a new key-value pair if the key is not found but our map here is a reference of a const map which do not allow inserting new key-value pairs.

## Exercise 11.35

**In buildMap, what effect, if any, would there be from rewriting**

```cpp
trans_map[key] = value.substr(1);
```
as
```cpp
trans_map.insert({key, value.substr(1)})?
```

When same key appears multiple times, using subscript operator will only keep the last time's key-value pair but using `insert` function will only keep the first time's key-value pair.

## Exercise 11.36

**Our program does no checking on the validity of either input file. In particular, it assumes that the rules in the transformation file are all sensible. What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.**

The program in the book will crash, but in my program (11.33), these situations will be checked and handled.

## Exercise 11.37

**What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?**

Aadvantages of an unordered container:

1. Has better peformance when the key type has no obvious ordering relationship among all elements.

2. Useful for applications where the cost of maintaining the elements in order is prohibitive.

Advantages of the ordered version:

1. We can use iterators of ordered containers to access all elements in order by key.

2. We can define an ordered container that uses a customized class type for its key type without defning `equal` or `hash` functions.

## Exercise 11.38

**Rewrite the word-counting (§ 11.1, p. 421) and word-transformation (§ 11.3.6, p. 440) programs to use an unordered_map.**

[word_count Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.38%20Solution.cpp)

[word_transformation Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.39%20Solution.cpp)
