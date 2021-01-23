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

[9.5 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.5%20Solution.cpp)
