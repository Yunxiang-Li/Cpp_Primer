# Chapter 6. Functions

## Exercise 6.1

**What is the difference between a parameter and an argument?**

A parameter is a local variable declared inside the function's parameter list. Parameters are initialized only when all arguments are provided in each function call.

Arguments are values provided in a function call which are used to initialize the function's all parameters.

## Exercise 6.2

**Indicate which of the following functions are in error and why. Suggest how you might correct the problems.**

```cpp
(a) int f() {
        string s;     
        // ...     
        return s;
    }
    
(b) f2(int i) { /* ... */ }

(c) int calc(int v1, int v1) /* ... */ }

(d) double square(double x) return x * x;
```

(a) Return type of function `f` is an integer but here we try to return a string which is wrong.

Correct version:

```cpp
string f() {
    string s;     
    // ...     
    return s;
}
```

(b) Function `f2` must have a return type, if no return values needed it should return void.

Correct version:

```cpp
void f2(int i) { /* ... */ }
```

(c) Function `calc` have duplicate parameters which is not allowed.

Correct version:

```cpp
int calc(int v1, int v2) /* ... */ }
```

(d)

Function blocks shoud be held in brackets.

Correct version:

```cpp
double square(double x) { return x * x; }
```

## Exercise 6.3

**Write and test your own version of fact.**

[6.3 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.3%20Solution.cpp)

## Exercise 6.4

**Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.**

[6.4 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.4%20Solution.cpp)

## Exercise 6.5

**Write a function to return the absolute value of its argument.**

[6.5 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.5%20Solution.cpp)

## Exercise 6.6

**Explain the differences between a parameter, a local variable, and a local static variable. Give an example of a function in which each might be useful.**

Parameter: A local variable declared inside the function parameter list

Local variable: A variable declared inside a block;

Local static variable: A variable initialized before the first time execution passes through the object’s definition. Local static variable is not destroyed when a function ends and it is destroyed only when the program terminates.

```cpp
size_t count_add(int n)       // Here n is a parameter.
{
    static size_t ctr = 0;    // Here ctr is a static variable.
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // Here i is a local variable.
      cout << count_add(i) << endl;

    return 0;
}
```

## Exercise 6.7

**Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.**

[6.7 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.7%20Solution.cpp)

## Exercise 6.8

**Write a header file named Chapter6.h that contains declarations for the functions you wrote for the exercises in § 6.1 (p. 205).**

[Chapter6.hpp](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/Chapter6.hpp)

## Exercise 6.9

**Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.**

[fact.cc](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/fact.cc)

[factMain.cc](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/factMain.cc)

## Exercise 6.10

**Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.**

[6.10 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.10%20Solution.cpp)

## Exercise 6.11

**Write and test your own version of reset that takes a reference.**

[6.11 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.11%20Solution.cpp)

## Exercise 6.12

**Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap the value of two ints. Which version do you think would be easier to use and why?**

[6.12 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.12%20Solution.cpp)

I think the reference version is easier since we do not need to care about pointers' process.

## Exercise 6.13

**Assuming T is the name of a type, explain the difference between a function declared as void f(T) and void f(T&).**

`void f(T)` pass the argument by value thus local variable `T` will not affect the input argument even `T` changes its value in the function `f(T)`. `void f(T&)` pass a reference which will bound with whatever T object we pass.

## Exercise 6.14

**Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.**

A parameter should be a reference type:

reset function from the book

```cpp
void reset(int &i)
{
        i = 0;
}
```

A parameter should not be a reference:

parameter **char** `c` of `find_char` function example in this chapter. We do not need to set `c` as a **const char&** since a **char** is already small enough for us to pass by value.

## Exercise 6.15

**Explain the rationale for the type of each of find_char’s parameters In particular, why is s a reference to const but occurs is a plain reference? Why are these parameters references, but the char parameter c is not? What would happen if we made s a plain reference? What if we made occurs a reference to const?**

Because parameter `s` should not be changed by this function. Hoever, parameter `occurs`'s result must be modified by the function.

We can set `c` as a **const char&** type here but it is not necessary since a **char** is already small enough for us to pass by value.

We can make `s` a plain refernce but then `s` will have risk of being modified. We cannot make `occurs` a const reference since then `occurs = 0` is an error since this line of code want to change `occurs`'s value which is not allowed.

## Exercise 6.16

**The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:**

```cpp
bool is_empty(string& s) { return s.empty(); }
```

This function takes a plain string reference as the parameter which will mislead users that the input string argument may be modified. Moreover, this function do not accept a const string reference as an input argument.

We should change the parameter from `string&` to `const string&`. 

Correct version:

```cpp
 bool is_empty(const string& s) { return s.empty(); }
```

## Exercise 6.17

**Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?**

[6.17 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.17%20Solution.cpp)

Not the same type. For the function `hasCapital` I use parameter `const string&`, since no modification needed for the input string argument. For the function `convertLower` I use parameter `string&` since this time we need to convert each uppercase letter from the input string argument to lowercase letter.

## Exercise 6.18

**Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.**

> (a) A function named compare that returns a bool and has two parameters that are references to a class named matrix.

```cpp
bool compare(const matrix& m1, const matrix& m2);
```

> (b) A function named change_val that returns a vector<int> iterator and takes two parameters: One is an int and the other is an iterator for a vector<int>.

```cpp
vector<int>::iterator change_val(const int a, vector<int>::iterator iter);
```

## Exercise 6.19

**Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.**

```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

(a) calc(23.4, 55.1);

(b) count("abcda", 'a');

(c) calc(66);

(d) sum(vec.begin(), vec.end(), 3.8);
```

(a) Illegal, function `calc` accepts one double value but here we provide two double values.

(b) Legal.

(c) Legal, function `calc` will convert input int `66` to a double value(66.0).

(d) Legal.

## Exercise 6.20

**When should reference parameters be references to const? What happens if we make a parameter a plain reference when it could be a reference to const?**

We should use const reference when we can. If we make a parameter a plain reference when it could be a reference to const, the reference value maybe changed(even not changed, this will mislead users that it may change). Moreover, const reference accept wider range of input types than plain reference.

## Exercise 6.21

**Write a function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points. What type should you use for the pointer?**

[6.21 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.21%20Solution.cpp)

I choose `const int* const` parameter type for the pointer since both the input pointer's address and the value it points to do not need to be modified.

## Exercise 6.22

**Write a function to swap two int pointers.**

[6.22 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.22%20Solution.cpp)

## Exercise 6.23

**Write your own versions of each of the print functions presented in this section. Call each of these functions to print i and j defined as follows:**

[6.23 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.23%20Solution.cpp)

## Exercise 6.24

**Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.**

```cpp
void print(const int ia[10])
{    
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

This function works well. The problem is although the input parameter is `const int ia[10]` this is actually equivalant to `const int* ia` which points to the first element of the array `ia`. Therefore the `i`'s upper bound will change if we want to input an array with different size.

If we want to strictly request that we can only input a 10-size array then we should change function parameter to `const int (&ia)[10]`

Correct version:

```cpp
void print(const int (&ia)[10])
{    
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

## Exercise 6.25

**Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting string.**

[6.25 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.25%20Solution.cpp)

## Exercise 6.26

**Write a program that accepts the options presented in this section. Print the values of the arguments passed to main.**

[6.26 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.26%20Solution.cpp)
