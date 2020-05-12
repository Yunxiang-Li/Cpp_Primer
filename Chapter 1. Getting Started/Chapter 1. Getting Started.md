# Chapter 1. Getting Started

## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

- Linux

![image](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Pictures/1.1.PNG)

## Exercise 1.2

> Exercise 1.2: Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

- Linux

![image](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Pictures/1.2.PNG)

## Exercise 1.3

> Write a program to print Hello, World on the standard output.

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

## Exercise 1.4

> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```cpp
#include <iostream>

int main() {

    std::cout << "Enter two numbers:";
    int v1, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;

    return 0;
}
```

## Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

```cpp
#include <iostream>

int main() {

    std::cout << "Enter two numbers:";
    int v1, v2 = 0;
    std::cin >> v1;
    std::cin >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout <<  v1 * v2;
    std::cout << std::endl;

    return 0;
}

```

## Exercise 1.6

> Explain whether the following program fragment is legal.

```cpp
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;
```

This program is illegal.

There should be no semicolons behind ```v1``` and ```v2```.

```cpp
std::cout << "The sum of " << v1
          << " and " << v2
          << " is " << v1 + v2 << std::endl;
```

## Exercise 1.7

> Compile a program that has incorrectly nested comments.

Example:

```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
  return 0;
}
```

Compiled result:

![ex1_7](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Pictures/1.7.PNG)

## Exercise 1.8

> Indicate which, if any, of the following output statements are legal:

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

> After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

Compiled result(g++):

![ex1_8](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Pictures/1.8.PNG)

I just added one more quote behind ```std::cout << /* "*/" */``` in third line to correct it

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```

Output:

```sh
    /**/ */ /*
```

## Exercise 1.9

>Write a program that uses a while to sum the numbers from 50 to 100.

```cpp
#include <iostream>

int main()
{
    int i = 50;
    int sum = 0;

    while (i < 101) {
        sum += i;
        i++;
    }
    std::cout << "The sum of numbers from 50 to 100 is " << sum << std::endl;
    
    return 0;
}
```

## Exercise 1.10

>In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.

```cpp
#include <iostream>

int main()
{
    int i = 10;

    while (i > -1) {
        std::cout << i << std::endl;
        i--;
    }
    
    return 0;
}
```

## Exercise 1.11

>Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

[1.11 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Codes/1.11%20Solution.cpp)

## Exercise 1.12

> What does the following for loop do? What is the final value of sum?

```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

This for loop add the sum of integers from -100 to 100 together, the final value is 0(since -100 + 100 = 0, -99 + 99 = 0, ..., -1 + 1 = 0, 0 = 0).

## Exercise 1.13

> Rewrite the exercises from 1.4.1 (p. 13) using for loops.

**Ex1.9**:

```cpp
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
        sum += i;

    std::cout << "the sum is: " << sum << std::endl;

    return 0;
}
```

**Ex1.10**:

```cpp
#include <iostream>

int main()
{
    for (int i = 10; i >= 0; --i)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
```

**Ex1.11**:

[Rewrite 1.11 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Codes/re%201.1%20Solution.cpp)

## Exercise 1.14

> Compare and contrast the loops that used a `for` with those using a `while`. Are there advantages or disadvantages to using either form?

- Advantage of `for` and disadvantage of `while`:
    - Locality, the variable in the scope of the loop.
    - Pattern happens so often: using a variable in a condition and incrementing that variable in the body.
- Advantage of `while` and disadvantage of `for`:
    - Clear when there is only one static condition.
    - Readable when the global variables incremented in the body.

## Exercise 1.15

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

**Skip**

## Exercise 1.16

> Write your own version of a program that prints the sum of a set of integers read from `cin`.

```cpp
#include <iostream>

int main()
{
    int number, sum = 0;
    std::cout << "Please input a set of integers: " << std::endl;

    while (std::cin >> number)
        sum += number;

    std::cout << "The sum of all input integers is: " << sum << std::endl;
    
    return 0;
}
```

## Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If all equal, the count of this number will be printed out. If there are no duplicated values, each line will be responsible for one single number.

## Exercise 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

![ex1_18_1](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Pictures/1.18_1.PNG)
![ex1_18_2](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Pictures/1.18_2.PNG)

## Exercise 1.19

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

[1.19 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Codes/1.11%20Solution.cpp)

## Exercise 1.20

> <http://www.informit.com/title/032174113> contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

You may also use [Sales_item.h](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Codes/Sales_item.h) here.

```cpp
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item;
    while (std::cin >> item) std::cout << item << std::endl;

    return 0;
}
```

![result](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Pictures/1.20.PNG)

## Exercise 1.21

> Write a program that reads two `Sales_item` objects that have the same ISBN and produces their sum.

The program should check whether the objects have the same ISBN.(check 1.5.2)

[1.21 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Codes/1.21%20Solution.cpp)

## Exercise 1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

[1.22 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Codes/1.22%20Solution.cpp).

## Exercise 1.23

> Write a program that reads several transactions and counts
how many transactions occur for each ISBN.

[1.23 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%201.%20Getting%20Started/Codes/1.23%20Solution.cpp).

## Exercise 1.24

> Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

**Skip**

## Exercise 1.25

> Using the `Sales_item.h` header from the Web site, compile and execute the bookstore program presented in this section.

**Skip**

