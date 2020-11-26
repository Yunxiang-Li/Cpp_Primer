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
