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
