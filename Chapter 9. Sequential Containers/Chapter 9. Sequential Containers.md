# Chapter 9. Sequential Containers

## Exercise 9.1

**Which is the most appropriate—a vector, a deque, or a list—for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.**

(a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem.

A `list` will be better in this situation. Beacuse we may need to insert each word in the middle according to the requirement of alphabetical order.

(b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.

A `deque` will be better in this situation. Because we need to always insert new words at the back and remove the next value from the front. `Deque` is much better than `vector` when it comes to inserting/removing an element from the front/back.

(c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

A `vector` will be better in this situation. Because we do not need to insert or delete any elements from the middle and we just need to read, sort and print thus `vector` will be better than `deque` since it saves more memory space.

## Exercise 9.2

**Define a list that holds elements that are deques that hold ints.**
```cpp
std::list<std::deque<int>> myList;
```

## Exercise 9.3

**What are the constraints on the iterators that form iterator ranges?**

Both two iterators(`begin` and `end`) must refer to elements of or one past the end of the same container. Moreover, it is possible to reach end by repeatedly incrementing `begin` which indicates `end` must not precede `begin`.

## Exercise 9.4

**Write a function that takes a pair of iterators to a `vector<int>` and an int value. Look for that value in the range and return a bool indicating whether it was found.**

[9.4 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.4%20Solution.cpp)

## Exercise 9.5

**Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.**

[9.5 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.5%20Solution.cpp)

## Exercise 9.6

**What is wrong with the following program? How might you correct it?**

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

All iterators are equality comparable. Only random access iterators are relationally comparable. Here, however, `std::list` container does not support random access thus we cannot write codes like `iter1 < iter2`. We should use `iter1 != iter2` instead.

Fixed version:

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 != iter2) /* ... */
```

## Exercise 9.7

**What type should be used as the index into a vector of ints?**

```cpp
vector<int>::size_type
```

## Exercise 9.8

**What type should be used to read elements in a list of strings? To write them?**

Both `list<string>::iterator` and `list<string>const_iterator` can be used to read elements in a list of strings but `list<string>const_iterator` is better.

`list<string>::iterator` should be used to write elements in a list of strings.

## Exercise 9.9

**What is the difference between the begin and cbegin functions?**

Function `begin` refers to the plain `iterator` of a container which can be used to both read and write the container's elements.

Function `cbegin` refers to the const `iterator` of a container which can only be used to read the container's elements.
