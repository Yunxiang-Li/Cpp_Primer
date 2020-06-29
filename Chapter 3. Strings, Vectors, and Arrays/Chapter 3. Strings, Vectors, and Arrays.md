# Chapter 3. Strings, Vectors, and Arrays

## Exercise 3.1

**Rewrite the exercises from § 1.4.1 and § 2.6.2 with appropriate using declarations.**

[3.1_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings,%20Vectors,%20and%20Arrays/Codes/3.1_1.cpp)

[3.1_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.1_2.cpp)

# Exercise 3.2

**Write a program to read the standard input a line at a time. Modify your program to read a word at a time.**

[3.2_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.2_1.cpp)

[3.2_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.2_2.cpp)

# Exercise 3.3

**Explain how whitespace characters are handled in the string input operator and in the getline function.**

The `getline` function takes an input stream and a string. This function reads the given stream up to and including the first newline and stores what it read—not including the newline—in its string argument. After `getline` sees a newline, even if it is the first character in the input, it stops reading and returns. If the first character in the input is a newline, then the resulting string is the empty string.

`getline` function whitespace handling, do not ignore the beginning of the line blank characters read characters until it encounters a line break, read to termination and discard newline (line breaks removed from the input stream but is not stored in the string object).

For `cin`, It will ignore the whitespace character if it is the first character, and stops reading and returns after meets the next whitespace character.

# Exercise 3.4

**Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.**

[3.4_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.4_1.cpp)

[3.4_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.4_2.cpp)

# Exercise 3.5

**Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.**

[3.5_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.5_1.cpp)

[3.5_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.5_2.cpp)

# Exercise 3.6

**Use a range for to change all the characters in a string to X.**

[3.6 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.6.cpp)

# Exercise 3.7

**What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.**

It will be no differences, since comipler will detect its type when we use `auto& c` and recognize it as `char& c`.

# Exercise 3.8

**Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?**

[3.8_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.8_1.cpp)

[3.8_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.8_2.cpp)

I prefer the range for one since it is the easiest one to write.

# Exercise 3.9 

**What does the following program do? Is it valid? If not, why not?**

```
string s;
cout << s[0] << endl;
```

Try to print the first element of the string but it is invalid since the s is not initialized thus this is an undefined behavior.

# Exercise 3.10 

**Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.**

[3.10 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.10.cpp)

# Exercise 3.11

**Is the following range `for` legal? If so, what is the type of `c`?**
```
const string s = "Keep out!";
for (auto &c : s) { /* ...  */ }
```

If we just read each `c`'s value, then it is legal. If we want to change each `c` 's value then it is illegal since `c`'s type is const char.

# Exercise 3.12

**Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.**

> (a) vector<vector<int>> ivec; 
  
legal
  
> (b) vector<string> svec = ivec;

illegal, ivec is of type `vector<int>`, svec is of type `string`, copy initialization cannot work here.
  
> (c) vector<string> svec(10, "null");

legal, svec now has 10 "null" elements.

# Exercise 3.13

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

# Exercise 3.14

**Write a program to read a sequence of ints from cin and store those values in a vector.**

[3.14 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.14.cpp)

# Exercise 3.15

**Repeat the previous program but read strings this time.**

[3.15 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.15.cpp)

# Exercise 3.16

**Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.**

[3.16 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.16.cpp)

# Exercise 3.17

**Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.**

[3.17 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.17.cpp)

# Exercise 3.18

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

# Exercise 3.19

**List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.**

[3.19 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.19.cpp)

I believe the first is the best since it is the shortest.

# Exercise 3.20

**Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.**

[3.20_1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.20_1.cpp)

[3.20_2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.20_2.cpp)

# Exercise 3.21

**Redo the first exercise from § 3.3.3 (p. 105) using iterators.**

[3.21 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.21.cpp)

# Exercise 3.22 

**Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you’ve updated text, print its contents.**

[3.22 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.22.cpp)

# Exercise 3.23

**Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.**

[3.23 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%203.%20Strings%2C%20Vectors%2C%20and%20Arrays/Codes/3.23.cpp)
