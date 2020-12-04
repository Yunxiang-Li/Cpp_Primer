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

## Exercise 6.27

**Write a function that takes an `initializer_list<int>` and produces the sum of the elements in the list.**

[6.27 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.27%20Solution.cpp)

## Exercise 6.28

**In the second version of error_msg that has an ErrCode parameter, what is the type of elem in the for loop?**

The type of `elem` in the for loop is `const std::string&`.

## Exercise 6.29

**When you use an initializer_list in a range for would you ever use a reference as the loop control variable? If so, why? If not, why not?**

Each element in the initializer_list is a const element. Therefore, if each element is just a basic type element then we do not need to use any reference since the cost of copy each element is already very low. However, for each other type element(like a complex class object) then we should use const reference.

## Exercise 6.30

**Compile the version of str_subrange as presented on page 223 to see what your compiler does with the indicated errors.**

g++ error:

```
error: return-statement with no value, in function returning 'bool' [-fpermissive]
       return; 
       ^~~~~~
```

My compiler failed to detect the error 2 D:.

## Exercise 6.31

**When is it valid to return a reference? A reference to const?**

It is valid to return a reference when the preexisted object that the reference refered to is still exist.

## Exercise 6.32

**Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.**

It is legal. Each iteration, `get(ia, i)` returns the reference to the `ia[i]` thus `get(ia, i)` method just assign each element `ia[i]` with value `i`.

The result from `ia[0]` to `ia[9]` are `0` to `9`.

## Exercise 6.33

**Write a recursive function to print the contents of a vector.**

[6.33 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.33%20Solution.cpp)

## Exercise 6.34

**What would happen if the stopping condition in factorial were**

```cpp
if (val != 0)
```
1. When users input a non-negative integer then everything works well as before.

2. When users input a negative integer then the program will have endless recursive calls of `factorial` method(for instance, -1 * -2 * -3 * ...). The program will have a stack overflow error.

## Exercise 6.35

**In the call to factorial, why did we pass val - 1 rather than val--?**

For line of codes

```cpp
return factorial(val - 1) * val;
```

If we use `val--` instead of `val - 1`, since `val--` will first be used in next recursive call and then decrement by one, then for each recursive call of `factorial` the `val` will never change which will lead program to endless recursive calls. Therefore, the program will then have a stack overflow error.

## Exercise 6.36

**Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.**

```cpp
string (&func())[10]
```

## Exercise 6.37

**Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?**

Type alias version:

```cpp
typedef string strArr[10]; // using strArr = string[10];
strArr& func();
```

Trailing return version:

```cpp
auto func -> string (&)[10];
```

Decltype version:

```cpp
string strArr[10];
decltype(strArr)& func();
```

## Exercise 6.38

**Revise the arrPtr function on to return a reference to the array.**

```cpp
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd)& arrPtr(int i)
{
    return (i % 2) ? odd : even;
}
```

## Exercise 6.39

**Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.**

```cpp
(a) int calc(int, int);
int calc(const int, const int);

(b) int get();
double get();

(c) int *reset(int *);
double *reset(double *);
```

(a) Illegal, since `const` in `const int` is a high const which will not affect the input(whether input int is a plain int or a const int). Therefore the compiler will not treat two functions as overloaded functions and thus function redeclaration is illegal.

(b) Illegal, compiler will not treat two functions as overloaded functions if the only difference is return type.

(c) Legal, both return type and parameter type are different thus compiler will treat two functions as overloaded functions.

## Exercise 6.40

**Which, if either, of the following declarations are errors? Why?**

```cpp
(a) int ff(int a, int b = 0, int c = 0);

(b) char *init(int ht = 24, int wd, char bckgrnd);
```

(a) Correct, default arguments should be specified from rightmost to leftmost.

(b) Wrong, if we want to set `ht`'s default value, we should set `wd` and `bckgrnd`'s default values first.

## Exercise 6.41

**Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer’s intent? Why?**

```cpp
char *init(int ht, int wd = 80, char bckgrnd = ' ');

(a) init();

(b) init(24,10);

(c) init(14, '*');
```

(a) Illegal, `ht` does not have default value.

(b) Legal, function will be called as `char* init(24, 10, ' ')`.

(c) Legal, but may not be what we expected. function will be called as `char* init(14, 42, ' ')` where 42 is the int value converted by the compiler from the char `*`. Actually user may want to call function as `init(14, 80, '*')` thus user should call like `init(14, ,'*')`. 

## Exercise 6.42

**Give the second parameter of make_plural (§ 6.3.2, p. 224) a default argument of 's'. Test your program by printing singular and plural versions of the words success and failure.**

[6.42 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.42%20Solution.cpp)

## Exercise 6.43

**Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.**

```cpp
(a) inline bool eq(const BigInt&, const BigInt&) {...}

(b) void putValues(int *arr, int size);
```
 
(a) I will put inline function's declaraion and definition in a header because of two reasons. One is about definition rule (ODR) for inline functions, an identical definition for the function must exist in every translation unit that uses it. The second reason is that we do not need to define this inline function again in each source file which will optimize the program's performance.

(b) I will also put this function's declaration in a header file since it is just a normal function.

## Exercise 6.44

**Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.**

[header file for inline function](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/inline.hpp)

[source file](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.44%20Solution.cpp)

## Exercise 6.45

**Review the programs you’ve written for the earlier exercises and decide whether they should be defined as inline. If so, do so. If not, explain why they should not be inline.**

All functions with exactly one valid statement(null statement does not count) which are used more than once should be defined as inline functions. All other functions should be just normal functions.

## Exercise 6.46

**Would it be possible to define isShorter as a constexpr? If so, do so. If not, explain why not.**

No, because if a function is a constexpr function and we can know its parameter result at compile time then we should know its exactly result or result sets at compile time.

Here, however, `std::string.size()` is not a constexpr function thus we cannot know the result of `isShorter` function at compile time. Therefore, we cannot define `isShorter` as a constexpr function.

## Exercise 6.47

**Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that used recursion to print the contents of a vector to conditionally print information about its execution. For example, you might print the size of the vector on each call. Compile and run the program with debugging turned on and again with it turned off.**

[6.47 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.47%20Solution.cpp)

## Exercise 6.48

**Explain what this loop does and whether it is a good use of assert:**

```cpp
string s;

while (cin >> s && s != sought) { }  // empty body

assert(cin);
```

It is not a good use of assertion here. This `assert` will affect and terminate the program if user input `EOF` and this situation is very common. We usually use assertion to ensure uncommon situations should never happen.

## Exercise 6.49

**What is a candidate function? What is a viable function?**

A candidate function is a function with the same name as the called function and for which a declaration is visible at the point of the call. 

A viable function is a function must have the same number of parameters as there are arguments in the call, and the type of each argument must match—or be convertible to—the type of its corresponding parameter.

## Exercise 6.50

**Given the declarations for f from page 242, list the viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.**

```cpp
(a) f(2.56, 42)

(b) f(42)

(c) f(42, 0)

(d) f(2.56, 3.14)
```

(a) Illegal, the call is ambiguous. 2.56 is a double which matches the double version `void f(double, double = 3.14)` but 42 is a int which matches the int version `void f(int, int)`. We have 2 viable functions thus compile cannot decide to use which.

(b) Legal, One int argument 42 thus the one int version `void f(int)` will be called.

(c) Legal, two int arguments thus two int version `void f(int, int)` will be called.

(d) Legal, two double arguments thus two double version `void f(double, double = 3.14)` will be called.

## Exercise 6.51

**Write all four versions of f. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.**

[6.51 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%206.%20Functions/Codes/6.51%20Solution.cpp)
