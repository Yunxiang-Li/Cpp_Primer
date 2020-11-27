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
