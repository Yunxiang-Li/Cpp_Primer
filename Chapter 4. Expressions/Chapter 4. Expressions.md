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

The prefix operators increment(or decrement) the operand first and return the incremented(or decremented) object as an lvalue.

The postfix operators first return a copy of the object's original value as an rvalue and then increment(or decrement) the operand.

## Exercise 4.18

**What would happen if the while loop on page 148 that prints the elements from a vector used the prefix increment operator?**

It will skip the first element, print from the second element and it will also try to dereference v.end() at last.(This is an undefined behavior and very dangerous)

## Exercise 4.19

**Given that ptr points to an int, that vec is a `vector<int>`, and that ival is an int, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?.**
    
```cpp
(a) ptr != 0 && *ptr++
(b) ival++ && ival
(c) vec[ival++] <= vec[ival]
```

(a) First check wheter `ptr` is a nullptr or not and check whether the pointer `ptr`'s value is zero of not and finally move on to `ptr`'s next element.

This expression is correct since left part of `&&` will be evaluated first.

(b) First check if `ival` is zero or not and then increment `ival` by one. Then check the new `ival` value whether it is zero or not.

This expression is correct since left part of `&&` will be evaluated first.

(c) This expression is incorrect since we do not know whether left part of `<=` will be evaluated first or the right part will be evaluated first thus this expression will cause an undefined bahavior.

## Exercise 4.20

**Assuming that iter is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.**

```cpp
(a) *iter++;

(b) (*iter)++;

(c) *iter.empty()

(d) iter->empty();

(e) ++*iter;

(f) iter++->empty();
```

(a) Legal, first dereference and get the string points by the `iter` iterator. Then move on to the next iterator.

(b) Illegal, first dereference and get the string points by the `iter` iterator. Then try to increment the string by one which is illegal.

(c) Illegal, `.` has higher order precedence than dereference. However, it is illegal to call `empty` member method on a string iterator.

(d) Legal, first dereference and get the string points by the `iter` iterator. Then call `empty` method on current string to check if it is an empty string.

(e) Illegal, first dereference and get the string points by the `iter` iterator. Then try to increment the string by one which is illegal.

(f) Legal, first dereference and call `empty` method on current string to check if it is an empty string. Then move on to the next iterator.

## Exercise 4.21

**Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element.**

[4.21 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%204.%20Expressions/Codes/4.21%20Solution.cpp)

## Exercise 4.22 

**Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more if statements. Which version do you think is easier to understand and why?**

[4.22 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%204.%20Expressions/Codes/4.22%20Solution.cpp)

## Exercise 4.23

**The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?**

```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

`+` operator has higher order precedence than `==` operator thus the second line will be `string pl = (s + s[s.size() - 1]) == 's' ? "" : "s" ;`.

First add `s` with `s[3]`(char `d` actually) and the result is a new string `wordd`. Then compare new string with the char `s`. However, we cannot use `==` to compare a string with a char thus codes cannot compile.

We can easily fix this issue by adding one more parenthesis.

```cpp
string s = "word";
string pl = s + (s[s.size() - 1] == 's') ? "" : "s" ;
```

## Exercise 4.24

**Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.**

Here is the program:

```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```

If the operator is left associative, then the program will be:

```cpp
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```

If the `grade` is lower or equal to 90, then we will evaluate `(grade < 60)` part instead of the later conditional statement. And then we will evaluate expression `true ? "fail" : "pass"` or `false ? "fail" : "pass"` according to the `grade`'s value. Therefore the final output can be "pass" or "fail".

If the `grade` is higher than 90, then first conditional statement will have result `"high pass"` and then we evaluate expression `"high pass" ? "fail" : "pass"` since `high pass` will always be converted to true when considered as a bool value thus this expression will always have true result so the final output will always be "fail".

## Exercise 4.25

**What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?**

Because `~` operator has a higher order precedence than `<<` operator thus we first evaluate `~'q'` which will get a negative value. Before C++ 20, left shift of a negative value is an undefined behaviour. Since C++ 20, the result is defined well and the result is `11111111111111111110001110000000`

## Exercise 4.26

**In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?**

There are altogether 30 students in the example. According to the standard, unsigned int is only guaranteed to hold at least 16 bits. If we choose unsigned int, the result may be undefined.

## Exercise 4.27

**What is the result of each of these expressions?**

```cpp
unsigned long ul1 = 3, ul2 = 7;
```

We can use bit representations for `3` and `7`:

`0011` for `3` and `0111` for `7`

> (a) ul1 & ul2

> (b) ul1 | ul2

> (c) ul1 && ul2

> (d) ul1 || ul2


(a) `0011` & `0111` => `0011` => `3`

(b) `0011` | `0111` => `0111` => `7`

(c) `0011` && `0111` => true

(d) `0011` || `0111` => true

## Exercise 4.28

**Write a program to print the size of each of the built-in types.**

[4.28 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%204.%20Expressions/Codes/4.28%20Solution.cpp)

## Exercise 4.29

**Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.**

```cpp
int x[10];
int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

First line of codes `cout << sizeof(x)/sizeof(*x) << endl;` will output the element number of the array. Because `sizeof(x)` will output each element type's size (int here) multiplies total element number of the array `x` and `sizeof(*x)` will output each element type's size (int here) thus `sizeof(x)/sizeof(*x)` will give us the total element number of the array `x` which is 10.

Second line of codes `cout << sizeof(p)/sizeof(*p) << endl;`'s result depends on system, I use 64-bit system thus `sizeof(p)` which will output the size of a pointer is 8. In practice, pointers will be 2 bytes on a 16-bit system, 3 bytes on a 24-bit system, 4 bytes on a 32-bit system, and 8 bytes on a 64-bit system. `sizeof(*p)` will output the size of the data type the pointer points to thus `sizeof(*p)` => `sizeof(int)` = 4. Therefore result on my machine is 8/4 => 2.

## Exercise 4.30

**Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:**

> (a) sizeof x + y

> (b) sizeof p->mem[i]

> (c) sizeof a < b

> (d) sizeof f()

(a) (sizeof x) + y `sizeof` operator has higher order precedence than `+`(add) operator.

(b) sizeof(p -> mem[i]) `sizeof` operator has lower order precedence than `+`(add) operator.

(c) sizeof(a) < b `sizeof` operator has higher order precedence than `<` operator.

(d) (sizeof f()) return the return type size of the function `f()`, if the return type is void then the result depends on compilers.

## Exercise 4.31

**The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.**

We used prefix just because the book said **Use Postfix Operators only When Necessary** before and also sometimes compilers can optimize prefix better than postfix.
It will be no changes whether we choose prefix or postfix in this program, here is the version of postfix:

```cpp
vector<int>::size_type cnt = ivec.size();
for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    ivec[ix] = cnt;
```

## Exercise 4.32

** Explain the following loop.**

```cpp
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr)   
{ /* ...   */ }
```

The loop use both pointer(ptr) and array index(ix) to traverse and do something on each array element. Two different ways to realize same feature.

## Exercise 4.33

**Using Table 4.12 (p. 166) explain what the following expression does:**

```cpp
someValue ? ++x, ++y : --x, --y
```

Because the `,` operator has the lowest order precedence thus the expression will be `(someValue ? ++x, ++y : --x), --y`.

First we check whether `someValue` has true or false value.

If true, then increment `x` by one, else increment `y` by one and the result of `(someValue ? ++x, ++y : --x),` part is `++y` and then we just discard the `someValue ? ++x, ++y : --x` part and decrement `y` by one thus the final result of the expression is just `y` if someValue is true.

If false, then decrement `x` by one and the result of `(someValue ? ++x, ++y : --x),` part is `--x`. However, since `(someValue ? ++x, ++y : --x),` part will always be discared then this expression's final result will always be `--y`.

To conclude, we may increment or decrement `x` by one but the result of this expression is always `y` or `--y` which has no relation with `x`.

## Exercise 4.34

**Given the variable definitions in this section, explain what conversions take place in the following expressions:**

> (a) if (fval)

> (b) dval = fval + ival;

> (c) dval + ival * cval;

**Remember that you may need to consider the associativity of the operators.**

(a) Convert `fval` from float to bool

(b) First convert `ival` from int to float and add `ival` with `fval`. Then convert the sum from float to double.

(c) First convert `cval` from char to int and multiply `ival` with `cval`. Then convert the sum from float to double.

## Exercise 4.35

**Given the following definitions,**

```cpp
char cval;     
int ival;
unsigned int ui;
float fval;
double dval;
```

**identify the implicit type conversions, if any, taking place:**

> (a) cval = 'a' + 3;

> (b) fval = ui - ival * 1.0;

> (c) dval = ui * fval;

> (d) cval = ival + fval + dval;

(a) First promote `a` from char to int and add with `3`. Then convert the sum from int back to char.

(b) First convert `ival` from int to double and multiply `ival` with 1.0. Then convert `ival` from int to double and add with the previous double sum. Finally convert result from double back to float by truncation.

(c) First promote `ui` from unsigned int to float and multiply with `fval`. Then convert the result to double.

(d) First promote `ival` from int to float and add with `fval`. Then promote the result from float to double and add with `dval`. Finally convert result from double back to char by truncation.

## Exercise 4.36

**Assuming i is an int and d is a double write the expression `i *= d` so that it does integral, rather than floating-point, multiplication.**

```cpp
i *= static_cast<int>(d);
```

## Exercise 4.37

**Rewrite each of the following old-style casts to use a named cast:**

```cpp
int i;
double d;
const string *ps;
char *pc;
void *pv;
```

> (a) pv = (void*)ps;

> (b) i = int(* pc);

> (c) pv = &d;

> (d) pc = (char*) pv;

(a) pv = static_cast<void*>(const_cast<string*>(ps));

(b) i = static_cast<int>(*pc);

(c) pv = static_cast<void*>(&d);

(d) pc = static_cast<char*>(pv);

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

