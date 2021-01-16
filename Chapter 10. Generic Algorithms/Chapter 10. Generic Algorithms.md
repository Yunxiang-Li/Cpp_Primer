# Chapter 10. Generic Algorithms

## Exercise 10.1

**The algorithm header defines a function named count that, like find, takes a pair of iterators and a value. count returns a count of how often that value appears. Read a sequence of ints into a vector and print the count of how many elements have a given value.**

[10.1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.1%20Solution.cpp)

## Exercise 10.2

**Repeat the previous program, but read values into a list of strings.**

[10.2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.2%20Solution.cpp)

## Exercise 10.3

**Use accumulate to sum the elements in a `vector<int>`.**

[10.3 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.3%20Solution.cpp)

## Exercise 10.4

**Assuming v is a `vector<double>`, what, if anything, is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?**

The result of `accumulate(v.cbegin(), v.cend(), 0)` will be converted into an interger instead of a double since the third argument `0` is an integer and `accumulate` function will return the result with the exact same type as the third argument.

## Exercise 10.5

**In the call to equal on rosters, what would happen if both rosters held C-style strings, rather than library strings?**

[10.5 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.5%20Solution.cpp)

When it comes to C-style strings, we should use `strlen` function from <cstring> header instead of `std::equal` function.

The `std::equal` function on C-style string will only compare by the relational operator(`==` here) which will only compare two C-style strings' address.  

## Exercise 10.6

**Using fill_n, write a program to set a sequence of int values to 0.**

[10.6 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.6%20Solution.cpp)

## Exercise 10.7

**Determine if there are any errors in the following programs and, if so, correct the error(s):**

(a)
```cpp
vector<int> vec;
list<int> lst;
int i;
while (cin >> i)
  lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
```

Incorrect, `copy(lst.cbegin(), lst.cend(), vec.begin())` requires `vec`'s size is at least same as `lst`. However, `vec` here is empty. We can fix this by resize `vec` before the `copy` function.

Fixed Version:

```cpp
vector<int> vec;
list<int> lst;
int i;
while (cin >> i)
  lst.push_back(i);
vec.resize(lst.size());
copy(lst.cbegin(), lst.cend(), vec.begin());
```

(b)
```cpp
vector<int> vec;
vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
fill_n(vec.begin(), 10, 0);
```

Syntax is correct, but the `vec`'s size is still 0 and no elements are set. We can also use `resize` function instead of `reverse` to fix this.

Fixed Version:

```cpp
vector<int> vec;
vec.resize(10); // reserve is covered in § 9.4 (p. 356)
fill_n(vec.begin(), 10, 0);
```

## Exercise 10.8

**We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?**

Because it is the `back_inserter`(an insert iterator) which uses containers' operations to change the size of containers not algorithms.

## Exercise 10.9

**Implement your own version of elimDups. Test your program by printing the vector after you read the input, after the call to unique, and after the call to erase.**

[10.9 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.9%20Solution.cpp)

## Exercise 10.10

**Why do you think the algorithms don’t change the size of containers?**

Because algorithms only operate on iterators, not containers. Therefore, algorithms cannot (directly) add or remove elements. C++ is designed so for seperating container operations and algorithms.

## Exercise 10.11

**Write a program that uses stable_sort and isShorter to sort a vector passed to your version of elimDups. Print the vector to verify that your program is correct.**

[10.11 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.11%20Solution.cpp)

## Exercise 10.12

**Write a function named compareIsbn that compares the isbn() members of two Sales_data objects. Use that function to sort a vector that holds Sales_data objects.**

[10.12 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.12%20Solution.cpp)

## Exercise 10.13

**The library defines an algorithm named partition that takes a predicate and partitions the container so that values for which the predicate is true appear in the first part and those for which the predicate is false appear in the second part. The algorithm returns an iterator just past the last element for which the predicate returned true. Write a function that takes a string and returns a bool indicating whether the string has five characters or more. Use that function to partition words. Print the elements that have five or more characters.**

[10.13 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.13%20Solution.cpp)

## Exercise 10.14

**Write a lambda that takes two ints and returns their sum.**

```cpp
  auto result = [](const int first, const int second) -> int { return (first + second); };
```

## Exercise 10.15

**Write a lambda that captures an int from its enclosing function and takes an int parameter. The lambda should return the sum of the captured int and the int parameter.**

```cpp
  int first{10};
  auto res = [first](int second) -> int {return first + second;};
```

## Exercise 10.16

**Write your own version of the biggies function using lambdas.**

[10.16 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.16%20Solution.cpp)

## Exercise 10.17

**Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda in the call to sort instead of the compareIsbn function.**

[10.17 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.17%20Solution.cpp)

## Exercise 10.18

**Rewrite biggies to use partition instead of find_if. We described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).**

[10.18 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.18%20Solution.cpp)

## Exercise 10.19

**Rewrite the previous exercise to use stable_partition, which like stable_sort maintains the original element order in the paritioned sequence.**

[10.19 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.19%20Solution.cpp)

## Exercise 10.20

**The library defines an algorithm named count_if. Like find_if, this function takes a pair of iterators denoting an input range and a predicate that it applies to each element in the given range. count_if returns a count of how often the predicate is true. Use count_if to rewrite the portion of our program that counted how many words are greater than length 6.**

[10.20 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.20%20Solution.cpp)

## Exercise 10.21

**Write a lambda that captures a local int variable and decrements that variable until it reaches 0. Once the variable is 0 additional calls should no longer decrement the variable. The lambda should return a bool that indicates whether the captured variable is 0.**

[10.21 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.21%20Solution.cpp)

## Exercise 10.22

**Rewrite the program to count words of size 6 or less using functions in place of the lambdas.**

[10.22 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.22%20Solution.cpp)

## Exercise 10.23

**How many arguments does bind take?**

If binded function has `n` parameters, then `std::bind` function takes `n + 1` parameters(One additional parameter for the binded functio name).

## Exercise 10.24

**Use bind and check_size to find the first element in a vector of ints that has a value greater than the length of a specified string value.**

[10.24 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.24%20Solution.cpp)

## Exercise 10.25

**In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies that uses partition. Rewrite that function to use check_size and bind.**

[10.25 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2010.%20Generic%20Algorithms/Codes/10.25%20Solution.cpp)

## Exercise 10.26

**Explain the differences among the three kinds of insert iterators.**
