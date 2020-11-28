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
