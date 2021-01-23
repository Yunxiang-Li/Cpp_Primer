# Chapter 11. Associative Containers

## Exercise 11.1

**Describe the differences between a map and a vector.**

A `map` is an associative container of key-value pairs. Each value is binded to a key thus we can get a value by its key.

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

`map` : Store key-value pairs such as {key, value} and each value is binded to a key.

Use `set` when we only need to store one type of elements and `map` when we need to store key-value pairs.
