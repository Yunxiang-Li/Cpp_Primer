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

Yes, I consider this an acceptable trade-off since in C++, performance is the most important thing and we can use parenthesis to avoid undefined behavior.

## Exercise 4.4

**Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.**

> 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2

((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2) result is 91.

## Exercise 4.5

**Determine the result of the following expressions.**

```cpp
(a) -30 * 3 + 21 / 5

(b) -30 + 3 * 21 / 5

(c) 30 / 3 * 21 % 5

(d) -30 / 3 * 21 % 4
```

(a) -86

(b) -18

(c) 0

(d) -2

## Exercise 4.6

**Write an expression to determine whether an int value is even or odd.**

```cpp
value % 2 == 0 ? "This int is even" : "This int is odd"
```

## Exercise 4.7

**What does overflow mean? Show three expressions that will overflow.**

```cpp
short svalue = 32767; ++svalue; // expected to be 32768, but actually -32768

unsigned uivalue = 0; --uivalue;  // expected to be -1, but actually 4294967295

unsigned short usvalue = 65535; ++usvalue;  // expected to be 65536, but actually 0
```

## Exercise 4.8

**Explain when operands are evaluated in the logical AND, logical OR, and equality operators.**

- logical **AND** : the second operand is evaluated if and only if the left side is true.

- logical **OR** : the second operand is evaluated if and only if the left side is false.

- equality operators : true only if both operands have the same value, otherwise, it returns false.

## Exercise 4.9 

**Explain the behavior of the condition in the following if:**

```Cpp
const char *cp = "Hello World";
if (cp && *cp)
```

`cp` is a pointer to a const char and `*cp` is a const char, and it's not a nullptr.

In this `if` clause, we first check whether pointer `cp` is `nullptr` or not(it's not).

Then we check whether `*cp`'s content is an empty char or not(it's not either).

Therefore the value of this `if` clause is true since `true && true => true.`

## Exercise 4.10 

**Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.**

```cpp
int a;
while(cin >> a && a != 42)
```

## Exercise 4.11

**Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, which is greater than c, which is greater than d.**

```cpp
a > b && b > c && c > d
```

## Exercise 4.12

**Assuming i, j, and k are all ints, explain what i != j < k means.**

`<` has higher precedence than `!=` thus `i != j < k` is just `i != (j < k)`.

Therefore this expression first checkes whether j is less than k and return a bool value (true if yes and false if no). 

Then we check whether i is not equal to 1(true) or 0(false).

## Exercise 4.13

**What are the values of i and d after each assignment?**

```cpp
int i;
double d;
```

> (a) d = i = 3.5;

> (b) i = d = 3.5;

(a) i = 3, d = 3.0

(b) d = 3.5, i = 3

## Exercise 4.14

**Explain what happens in each of the if tests:**

```cpp
if (42 = i)   //  Compile error: arithmetic literal cannot be lvalue.
if (i = 42)   //  First assign 42 to i, then since i is non-zero thus if(i) is always true.
```

## Exercise 4.15

**The following assignment is illegal. Why? How would you correct it?**

```cpp
double dval;
int ival;
int *pi;
dval = ival = pi = 0;
```
because pi is an int pointer and we cannot assign an int pointer's value to an int(this is not convertable).

Correct it:

```cpp
double dval;
int ival;
int *pi;
dval = ival = *pi = 0;
```

## Exercise 4.16

**Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.**

```cpp
(a) if (p = getPtr() != 0)
(b) if (i = 1024)
```

(a) Because `=`'s precedence is lower than `!=`, thus this expression will be `if (p = (getPtr() != 0))`. First check if `getPtr()` is equal to 0 or not and then assign the boolean result to `p` and finally check if `p` has bool value true or false.

I believe that the programmer actually want to assign `getPtr()`'s value to `p` and then check if `p`'s value is equal to 0 or not.

Therefore we can rewrite like this `if ((p = getPtr()) != 0)`

(b) This expression first assign 1024 to `i` and then check `i`'s bool value. Because `i` is non-zero then `i`'s bool value is always true thus this expression is always ture.

I believe that the programmer actually want to check if `i` is equal to 1024 so we can rewrite like this `if (i == 1024)`

## Exercise 4.17

**Explain the difference between prefix and postfix increment.**

## Exercise 4.18

**What would happen if the while loop on page 148 that prints the elements from a vector used the prefix increment operator?**

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

