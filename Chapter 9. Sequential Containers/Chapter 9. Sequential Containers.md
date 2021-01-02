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

Both `list<string>::iterator` and `list<string>::const_iterator` can be used to read elements in a list of strings but `list<string>const_iterator` is better.

`list<string>::iterator` should be used to write elements in a list of strings.

## Exercise 9.9

**What is the difference between the begin and cbegin functions?**

Function `begin` refers to the plain `iterator` of a container which can be used to both read and write the container's elements.

Function `cbegin` refers to the const `iterator` of a container which can only be used to read the container's elements.

## Exercise 9.10

**What are the types of the following four objects?**

```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

`v1` is of type `vector<int>::iterator`, `v2` is of type `vector<int>::const_iterator`, `v3` is of type `vector<int>::cosnt_iterator` and `v4` is of type `vector<int>::const_iterator`.

## Exercise 9.11

**Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.**

```cpp
std::vector<int> vec;    // Empty
std::vector<int> vec(10);    // 10 int elements and each has default value 0
std::vector<int> vec(10,1);  // 10 int elements and each has value 1
std::vector<int> vec{1,2,3,4,5}; // 5 int elements. Altogether values are 1, 2, 3, 4 and 5
std::vector<int> vec(anotherVec); // vec has same elements' numbers and values as anotherVec
std::vector<int> vec(anotherVec.begin(), anotherVec.end()); // vec has same elements' numbers and values as anotherVec
```

## Exercise 9.12

**Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.**

The constructor that takes another container as an argument (excepting array) requires the container type and element type of both containers to be exactly identical. It will copy all elements of the copied container into the new one.

The constructor that takes two iterators as arguments does not require the container type and element type to be exactly identical. Moreover, the element type in the new and original containers can differ as long as it is possible to convert elements we’re copying to the element type of the container we are initializing. It will only copy all elements between two iterators(left inclusive, right exclusive).

## Exercise 9.13

**How would you initialize a `vector<double>` from a `list<int>`? From a `vector<int>`? Write code to check your answers.**

[9.13 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.13%20Solution.cpp)

## Exercise 9.14

**Write a program to assign the elements from a list of `char*` pointers to C-style character strings to a vector of strings.**

[9.14 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.14%20Solution.cpp)

## Exercise 9.15

**Write a program to determine whether two `vector<int>`s are equal.**

[9.15 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.15%20Solution.cpp)

## Exercise 9.16

**Repeat the previous program, but compare elements in a `list<int>` to a `vector<int>`.**

[9.16 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.16%20Solution.cpp)

## Exercise 9.17

**Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?**

```cpp
if (c1 < c2)
```

1. Both `c1` and `c2` should be the same container type(but not any associative container types).

2. Elements of two containers should be of same type.

3. Elements type should support relational operators.

## Exercise 9.18

**Write a program to read a sequence of strings from the standard input into a deque. Use iterators to write a loop to print the elements in the deque.**

[9.18 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.18%20Solution.cpp)

## Exercise 9.19

**Rewrite the program from the previous exercise to use a list. List the changes you needed to make.**

[9.19 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.19%20Solution.cpp)

## Exercise 9.20

**Write a program to copy elements from a `list<int>` into two deques. The even-valued elements should go into one deque and the odd ones into the other.**

[9.20 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.20%20Solution.cpp)

## Exercise 9.21

**Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.**

It works the same way as `list`.

Before the loop, we initialize iter to `vec.begin()`. The first call to insert takes the string we just read and puts it in front of the element denoted by `iter`. The value returned by insert is an iterator referring to this new element. We assign that iterator to `iter` and repeat the while, reading another word. As long as there are words to insert, each trip through the while inserts a new element ahead of `iter` and reassigns to `iter` the location of the newly inserted element. That element is the (new) first element. Thus, each iteration inserts an element ahead of the first element in the list.

## Exercise 9.22

**Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?**

```cpp
vector<int>::iterator iter = iv.begin(), mid= iv.begin() + iv.size()/2;
while (iter != mid) 
  if (*iter == some_val) 
    iv.insert(iter, 2 * some_val);
```

This while loop is an endless loop since `iter` will never change. Moreover, after insertion `mid` iterator will be invalid.

Fixed version:

[9.22 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.22%20Solution.cpp)

## Exercise 9.23

**In the first program in this section on page 346, what would the values of val, val2, val3, and val4 be if c.size() is 1?**

`val`, `val2`, `val3` and `val4` will all have the same value since they all refer to the same element(the only element).

## Exercise 9.24

**Write a program that fetches the first element in a vector using at, the subscript operator, front, and begin. Test your program on an empty vector.**

[9.24 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.24%20Solution.cpp)

## Exercise 9.25

**In the program on page 349 that erased a range of elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?**

If `elem1` and `elem2` are equal, then no elements will be erased since `erase(begin, end)` function is left inclusive and right exclusive([left, right)).

If `elem2` is the off-the-end iterator, then elements from `elem1` to the element before `elem2` will be erased and the off-the-end iterator will be returned.

If both `elem1` and `elem2` are the off-the-end iterator then nothing happens like the situation mentioned above that `elem1` and `elem2` are equal.

## Exercise 9.26

**Using the following definition of ia, copy ia into a vector and into a list. Use the single-iterator form of erase to remove the elements with odd values from your list and the even values from your vector.**

```cpp
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```

[9.26 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.26%20Solution.cpp)

## Exercise 9.27

**Write a program to find and remove the odd-valued elements in a `forward_list<int>` .**

[9.27 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.27%20Solution.cpp)

## Exercise 9.28

**Write a function that takes a `forward_list<string>` and two additional string arguments. The function should find the first string and insert the second immediately following the first. If the first string is not found, then insert the second string at the end of the list.**

[9.28 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%209.%20Sequential%20Containers/Codes/9.28%20Solution.cpp)

## Exercise 9.29

**Given that vec holds 25 elements, what does vec.resize(100) do? What if we next wrote vec.resize(10)?**

`vec.resize(100)` will add 75(100 - 25 = 75) elements which are value initialized to the `vec`.

If we next wrote `vec.resize(10)` then from the 11th element to the 100th element of `vec` will be discarded.

## Exercise 9.30

**What, if any, restrictions does using the version of resize that takes a single argument place on the element type?**

If we use the version of `resize` that takes a single argument place on the element type, we must supply an initializer or the element type must have a default constructor since all elements should be value initialized.
