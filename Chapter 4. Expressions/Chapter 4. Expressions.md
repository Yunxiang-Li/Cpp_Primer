# Chapter 4. Expressions

## Exercise 4.1

**What is the value returned by 5 + 10 * 20/2?**

The return value is 105. ((10 * 20) / 2)) + 5

## Exercise 4.2

**Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:**

```Cpp
(a) * vec.begin()

(b) * vec.begin() + 1
```

(a) * (vec.begin())

(b) (* (vec.begin())) + 1

## Exercise 4.3

**Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?**

Yes

## Exercise 3.4

**Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.**

[3.4_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.4_1.cpp)

[3.4_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.4_2.cpp)

## Exercise 3.5

**Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.**

[3.5_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.5_1.cpp)

[3.5_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.5_2.cpp)

## Exercise 3.6

**Use a range for to change all the characters in a string to X.**

[3.6 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.6.cpp)

## Exercise 3.7

**What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.**

It will be no differences, since comipler will detect its type when we use `auto& c` and recognize it as `char& c`.

## Exercise 3.8

**Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?**

[3.8_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.8_1.cpp)

[3.8_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.8_2.cpp)

I prefer the range for one since it is the easiest one to write.

## Exercise 3.9 

**What does the following program do? Is it valid? If not, why not?**

```
string s;
cout << s[0] << endl;
```

Try to print the first element of the string but it is invalid since the s is not initialized thus this is an undefined behavior.

## Exercise 3.10 

**Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.**

[3.10 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.10.cpp)

## Exercise 3.11

**Is the following range `for` legal? If so, what is the type of `c`?**
```
const string s = "Keep out!";
for (auto &c : s) { /* ...  */ }
```

If we just read each `c`'s value, then it is legal. If we want to change each `c` 's value then it is illegal since `c`'s type is const char.

## Exercise 3.12

**Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.**

> (a) vector<vector<int>> ivec; 
  
legal
  
> (b) vector<string> svec = ivec;

illegal, ivec is of type `vector<int>`, svec is of type `string`, copy initialization cannot work here.
  
> (c) vector<string> svec(10, "null");

legal, svec now has 10 "null" elements.

## Exercise 3.13

**How many elements are there in each of the following vectors? What are the values of the elements?**

> (a) vector<int> v1; 
  
  0 element.
  
> (b) vector<int> v2(10);
  
  10 elements with 0(default) value.
  
> (c) vector<int> v3(10, 42);
  
  10 elements with `42` value.
  
> (d) vector<int> v4{10};
  
  1 element with `10` value.
  
> (e) vector<int> v5{10, 42};
  
  2 elements with `10` and `42` value.
  
> (f) vector<string> v6{10};
  
  10 elements with "" value.
  
> (g) vector<string> v7{10, "hi"};

  10 elements with "hi" value.

## Exercise 3.14

**Write a program to read a sequence of ints from cin and store those values in a vector.**

[3.14 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.14.cpp)

## Exercise 3.15

**Repeat the previous program but read strings this time.**

[3.15 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.15.cpp)

## Exercise 3.16

**Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.**

[3.16 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.16.cpp)

## Exercise 3.17

**Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.**

[3.17 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.17.cpp)

## Exercise 3.18

**Is the following program legal? If not, how might you fix it?**

Not legal, because `ivec` is initialized as an empty vector which means its size is 0, thus using subscript to access first element of `ivec` is an undefined behavior.

```
vector<int> ivec;
ivec[0] = 42;
```
We can fix it like this:
```
#include <vector>

using std::vector;

int main()
{
    vector<int> ivec(1);
    ivec[0] = 42;
    return 0;
}
```
Or:
```
#include <vector>

using std::vector;

int main()
{
    vector<int> ivec{0};
    ivec[0] = 42;
    return 0;
}
```

## Exercise 3.19

**List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.**

[3.19 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.19.cpp)

I believe the first is the best since it is the shortest.

## Exercise 3.20

**Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.**

[3.20_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.20_1.cpp)

[3.20_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.20_2.cpp)

## Exercise 3.21

**Redo the first exercise from § 3.3.3 (p. 105) using iterators.**

[3.21 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.21.cpp)

## Exercise 3.22 

**Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you’ve updated text, print its contents.**

[3.22 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.22.cpp)

## Exercise 3.23

**Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.**

[3.23 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.23.cpp)

## Exercise 3.24

**Redo the last exercise from § 3.3.3 (p. 105) using iterators.**

[3.24_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.24_1.cpp)

[3.24_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.24_2.cpp)

## Exercise 3.25

**Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.**

[3.25 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.25.cpp)

## Exercise 3.26

In the binary search program on page 112, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) /2;`?

Because [the iterator of vector don't define the + operator between the two iterators](http://www.cplusplus.com/reference/iterator/RandomAccessIterator/). It is illegal to add two iterators.

We can only use the subtraction between the two iterators.

## Exercise 3.27

**Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.**

> unsigned buf_size = 1024;

(a) int ia[buf_size];

Illegal, ia's dimension value must be a constant expression.

(b) int ia[4 * 7 - 14];

Legal, ia's dimension value is a constant expression(14 here).

(c) int ia[txt_size()];

Illegal, The dimension value must be a constant expression. We can change `txt_size()` function to `constexpr`

(d) char st[11] = "fundamental";

Illegal, the string's size is 11("fundamental" 's length) + 1('\0' null terminator's size) = 12 but the char array `st` can only hold 11 elements.

## Exercise 3.28

**What are the values in the following arrays?**
```
string sa[10];
int ia[10];
int main() {
    string sa2[10];
    int    ia2[10];
}
```
string is not a built-in type, thus compiler will set it to empty, `sa = ""` and `sa2 = ""`(size does not matter here), integer is a built-in type, and int array `ia` is out of any functions, thus `ia = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}`, `ia2` is in main function, thus its value is undefined.

## Exercise 3.29

**List some of the drawbacks of using an array instead of a vector.**

- 1. Array's size is fixed after it is initialized, thus we cannot modify its size even when we need to.
- 2. Arrays have to be deallocated explicitly if defined dynamically whereas vectors are automatically de-allocated from heap memory.
- 3. Arrays cannot be returned unless dynamically allocated from a function whereas vectors can be returned from a function.

## Exercise 3.30

**Identify the indexing errors in the following code:**

```
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)      
  ia[ix] = ix;
```

Size of `ia` is 10, so the largest index of `ia` is 9 (index starts from 0). `ix` cannot be 10(larger than the largest index of `ia`).

## Exercise 3.31

**Write a program to define an array of ten ints. Give each element the same value as its position in the array.**

[3.31 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.31.cpp)

## Exercise 3.32

**Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.**

[3.32_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.32_1.cpp)

[3.32_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.32_2.cpp)

## Exercise 3.33

**What would happen if we did not initialize the scores array in the program on page 116?**

If we did not initialize the `scores` array, since the array is in the main function, thus the array is undefined(built-in type int will not be initialized as 0 if it is inside any functions. This attempt is an undefined behavior.

## Exercise 3.34

**Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or p2 that make this code illegal?**

> p1 += p2 - p1;

`p1 += p2 - p1;` means `p1 = p1 + ptrdiff_t(p2 - p1) = p2;`

Here comes a tricky part, if we directly write  `p1 = p1 + p2 - p1` the compiler will not compile since it will try calculate `p1 + p2` first, we can not add two pointers together since operator `+` is not defined here. This code is very smart and if `p2` and `p1` are legal then this code is always legal.

## Exercise 3.35

**Using pointers, write a program to set the elements in an array to zero.**

[3.35 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.35.cpp)

## Exercise 3.36

**Write a program to compare two arrays for equality. Write a similar program to compare two vectors.**

[3.36_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.36_1.cpp)

[3.36_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.36_2.cpp)

## Exercise 3.37

**What does the following program do?**

```
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) 
{    
cout << *cp << endl;    ++cp;
}
```

Print all elements of the array `ca`.

## Exercise 3.38

**In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?**

Because Subtracting two points gives a logically explainable result - the offset in memory between two points. Similarly, you can subtract or add an integral number to/from a pointer, which means "move the pointer up or down". Adding a pointer to a pointer is something which is hard to explain. The result is meaningless.

## Exercise 3.39

**Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.**

[3.39_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.39_1.cpp)

[3.39_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.39_2.cpp)

## Exercise 3.40

**Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use strcpy and strcat to copy the two arrays into the third.**

[3.40 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.40.cpp)

## Exercise 3.41

**Write a program to initialize a vector from an array of ints.** 

[3.41 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.41.cpp)

## Exercise 3.42

**Write a program to copy a vector of ints into an array of ints.**

[3.42 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.42.cpp)

# Exercise 3.43

**Write three different versions of a program to print the elements of ia. One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, auto, or decltype to simplify the code.**

[3.43 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.43.cpp)

# Exercise 3.44

**Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.**

[3.44 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.44.cpp)

# Exercise 3.45

**Rewrite the programs again, this time using auto.**

[3.45 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.45.cpp)

