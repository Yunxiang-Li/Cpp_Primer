# Chapter 8. The IO Library

## Exercise 9.1

**Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.**

## Exercise 2.2

> To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

use `double` because:

- The rate is most like: `1.50 % per year`.

- The principal most like that: `$100.12`

- The payment most like that: `$2,188.66`

When it comes to **money**, precision **matters**!

## Exercise 2.3

> What output will the following code produce?
>
> ```cpp
> unsigned u = 10, u2 = 42;
> std::cout << u2 - u << std::endl;
> std::cout << u - u2 << std::endl;
> int i = 10, i2 = 42;
> std::cout << i2 - i << std::endl;
> std::cout << i - i2 << std::endl;
> std::cout << i - u << std::endl;
> std::cout << u - i << std::endl;
> ```

```shell
32 4294967264 32 -32 0 0
```

## Exercise 2.4

> Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.

```cpp
#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    return 0;
}
```
![result](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%202.%20Variables%20and%20Basic%20Types/Pictures/2.4.PNG)

## Exercise 2.5

> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:
>
> - (a) 'a', L'a', "a", L"a"
> - (b) 10, 10u, 10L, 10uL, 012, 0xC
> - (c) 3.14, 3.14f, 3.14L
> - (d) 10, 10u, 10., 10e-2

(a): character literal, wide character literal, string literal, string wide character literal.

(b): decimal integer, unsigned decimal integer, long decimal integer, unsigned long decimal integer, octal integer, hexadecimal integer.

(c): double, float, long double.

(d): decimal integer, unsigned decimal integer, double, double.

## Exercise 2.6

> What, if any, are the differences between the following definitions:
>
> ```cpp
> int month = 9, day = 7;
> int month = 09, day = 07;
> ```

The first line's integers are decimal integers.

The second line's integers are all octal integers.

However:

1. `int month = 09` is invalid, cause octal don't have digit `9`.
2. `day` is an octal integer.

## Exercise 2.7

> What values do these literals represent? What type does each have?
>
> - (a) "Who goes with F\145rgus?\012"
> - (b) 3.14e1L
> - (c) 1024f
> - (d) 3.14L

(a): "Who goes with Fergus?(new line)
"

(b): 31.4 "long double"

(c): 1024 "float"

(d): 3.14 "long double"

Reference:

- [ASCII Table](http://www.asciitable.com/)

## Exercise 2.8

> Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.

```cpp
#include <iostream>

int main()
{
    std::cout << "\x32\x4D\xA";
    std::cout << "\x32\x9\x4D\xA";
    return 0;
}
```

## Exercise 2.9

> Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.
> - (a) `std::cin >> int input_value;`
> - (b) `int i = { 3.14 };`
> - (c) `double salary = wage = 9999.99;`
> - (d) `int i = 3.14;`

(a): error: expected primary-expression before ‘int’

```cpp
int input_value = 0;
std::cin >> input_value;
```

(b): error: narrowing conversion of ‘3.1400000000000001e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]

```cpp
double i = { 3.14 };
```

(c): if declared 'wage' before, it's right. Otherwise, error would be happened: `error: ‘wage’ was not declared in this scope`

```cpp
double wage;
double salary = wage = 9999.99;
```

(d): Ok: but value will be truncated.

```cpp
double i = 3.14;
```

## Exercise 2.10

> What are the initial values, if any, of each of the following variables?
>
> ```cpp
> std::string global_str;
> int global_int;
> int main()
> {
>     int local_int;
>     std::string local_str;
> }
> ```

- `global_str` is global variable, so the value is an empty string.
- `global_int` is global variable, so the value is `0`.
- `local_int` is a local variable which is not uninitialized, so it has an undefined value.
- `local_str` is also a local variable which is not uninitialized, but it has a value that is defined by the class. So it is also an empty string.

> Uninitialized objects of built-in type defined inside a function body have a undefined value. Objects of class type that we do not explicitly initialize have a value that is defined by class.

## Exercise 2.11

> Explain whether each of the following is a declaration or a definition:
> - (a) `extern int ix = 1024;`
> - (b) `int iy;`
> - (c) `extern int iz;`

- (a): definition.
- (b): definition.
- (c): declaration.

## Exercise 2.12

> Which, if any, of the following names are invalid?
> - (a) `int double = 3.14;`
> - (b) `int _;`
> - (c) `int catch-22;`
> - (d) `int 1_or_2 = 1;`
> - (e) `double Double = 3.14;`

`a`, `c`, `d` are invalid.

for `a`, double is a keyword we cannot use as variable name.

for `c`, `-` is not allowed in variable names.

for `d`, We cannot use numbers as start of a variable name.

## Exercise 2.13

> What is the value of j in the following program?
>
> ```cpp
> int i = 42;
> int main()
> {
>     int i = 100;
>     int j = i;
> }
> ```

`100`. cause the global `i` was hidden by the local `i`.

## Exercise 2.14

> Is the following program legal? If so, what values are printed?

```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

It is legal.Printed:`100, 45.`

## Exercise 2.15

> Which of the following definitions, if any, are invalid? Why?
> - (a) `int ival = 1.01;`
> - (b) `int &rval1 = 1.01;`
> - (c) `int &rval2 = ival;`
> - (d) `int &rval3;`

- (a): valid.
- (b): invalid. initializer must be an object or variable.
- (c): valid.
- (d): invalid. a reference must be initialized.

## Exercise 2.16

> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
>
> ```cpp
> int i = 0, &r1 = i;
> double d = 0, &r2 = d;
> ```
>
> - (a) r2 = 3.14159;
> - (b) r2 = r1;
> - (c) i = r2;
> - (d) r1 = d;

- (a): valid. let `d = 3.14159`
- (b): valid. automatic convert will happen.
- (c): valid. but value will be truncated.
- (d): valid. but value will be truncated. Same as (c)

## Exercise 2.17

> What does the following code print?
>
> ```cpp
> int i, &ri = i;
> i = 5; ri = 10;
> std::cout << i << " " << ri << std::endl;
> ```

`10, 10`

## Exercise 2.18

> Write code to change the value of a pointer. Write code to change the value to which the pointer points.

```cpp
int a = 1, b = 10;
int *p1 = &a, *p2 = p1;

// change the value of a pointer.
p1 = &b;
// change the value to which the pointer points
*p2 = b;
```
