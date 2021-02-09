# Chapter 12. Dynamic Memory


## Exercise 12.1

**How many elements do b1 and b2 have at the end of this code?**

```cpp
StrBlob b1;
{    
  StrBlob b2 = {"a", "an", "the"};
  b1 = b2;
  b2.push_back("about");
}
```

Because of the `shared_ptr`, both `b1` and `b2` will have 4 elements at the end of this code even after `b2` is out of scope.

## Exercise 12.2

**Write your own version of the StrBlob class including the const versions of front and back.**

[12.2 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.2%20Solution.hpp)

[12.2 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.2%20Solution.cpp)

## Exercise 12.3

**Does this class need const versions of push_back and pop_back? If so, add them. If not, why aren’t they needed?**

We can add const versions of `push_back` and `pop_back` but there are not any logical reasons. The compiler will not complain because this doesn't modify `m_data` (which is a `shared_ptr`) but things `m_data` points to which is a legal action.

## Exercise 12.4

**In our check function we didn’t check whether i was greater than zero. Why is it okay to omit that check?**

Because the type of `i` is `dataSize`(actually `std::vector<std::string>::size_type`) which is an unsigned integer thus `i` can never be less than `0`.

## Exercise 12.5

**We did not make the constructor that takes an initializer_list explicit (§ 7.5.4, p. 296). Discuss the pros and cons of this design choice.**

For this design choice(makes the constructor that takes an `initializer_list` explicit)

Pros:

When using the constructor with a single parameter, the compiler cannot convert a single input variable to be the right type for that constructor.

Therefore it is more clear for programmers.

Cons:

No harm but looks a little bit more redundant.

## Exercise 12.6

**Write a function that returns a dynamically allocated vector of ints. Pass that vector to another function that reads the standard input to give values to the elements. Pass the vector to another function to print the values that were read. Remember to delete the vector at the appropriate time.**

[12.6 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.6%20Solution.cpp)

## Exercise 12.7

**Redo the previous exercise, this time using shared_ptr.**

[12.7 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.7%20Solution.cpp)

## Exercise 12.8

**Explain what if anything is wrong with the following function.**

```cpp
bool b() 
{    
  int* p = new int;    
  // ...    
  return p;
}
```

`p` is originally a pointer to an integer,  `return p` just convert the `p` to be a bool thus we have no chance to free `p` as a pointer anymore. Therefore a memory leak will happen.

## Exercise 12.9

**Explain what happens in the following code:**

```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

For pointer `q` and `r`:

`q` points to an integer with value 42, `r` points to an integer with value 100. Then `r = q` makes `r` also point to the integer with value 42(what `q` points to) thus no one points to the integer with value 100 now. Therefore we have no change to free the dynamic memory of the integer with value 100 and a memory leak will happen.

For smart(`shared_ptr`) pointer `q2` and `r2`:

`q2` points to an integer with value 42, `r2` points to an integer with value 100. After `r2 = q2`, `r2` also points to the integer with value 42(what `q2` points to) thus no one points to the integer with value 100 now. Since `r2` is a `shared_ptr` and the count of `shared_ptr` which point to the integer with value 100 is 0 now, the `shared_ptr` will free the redundant memory automatically and there will be no memory leak at all.

## Exercise 12.10

**Explain whether the following call to the process function defined on page 464 is correct. If not, how would you correct the call?**

```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

Correct, `shared_ptr<int> p(new int(42))` will set the reference count of `p` to 1. When we call `process(shared_ptr<int>(p))`, we create another `shared_ptr<int> p` which sets the reference count of `p` to 2. After the `process(shared_ptr<int>(p))`, the `shared_ptr<int> p` inside the function is destroyed and the reference count of `p` is now 1 again.

## Exercise 12.11

**What would happen if we called process as follows?**

```cpp
process(shared_ptr<int>(p.get()));
```

This is illegal. `p.get()` function will return a built-in pointer which also points to where `p` points to. `shared_ptr<int>(p.get())` creates a new `shared_ptr` by the built-in pointer `p.get()`. After `process(shared_ptr<int>(p.get()))`, memory points by the newly generated `shared_ptr` will be freed since the function is already executed completely. Because both `shared_ptr<int> p` point to the same integer, if the outer scope ends, `shared_ptr<int> p` will also be freed again which will cause a double free issue.

## Exercise 12.12

**Using the declarations of p and sp explain each of the following calls to process. If the call is legal, explain what it does. If the call is illegal, explain why:**

```cpp
auto p = new int();
auto sp = make_shared<int>();
```

(a) `process(sp);`

Legal. Just pass a `shared_ptr` by value.

(b) `process(new int());`

Illegal. A plain pointer cannot be converted to a `shared_ptr` implicitly.

(c) `process(p);`

Also illegal. A plain pointer cannot be converted to a `shared_ptr` implicitly.

(d) `process(shared_ptr<int>(p));`
  
Legal, creates a `shared_ptr` by the plain pointer and pass it to the function by value.

## Exercise 12.13

**What happens if we execute the following code?**

```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```

Both `p` and `sp` point to the same memory, we already free the memory by `delete p`, memory will be freed again if out of the scope of `sp` which will cause a double free issue.

## Exercise 12.14

**Write your own version of a function that uses a shared_ptr to manage a connection.**

[12.14 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.14%20Solution.cpp)

## Exercise 12.15

**Rewrite the first exercise to use a lambda (§ 10.3.2, p. 388) in place of the end_connection function.**

[12.15 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.15%20Solution.cpp)

## Exercise 12.16

**Compilers don’t always give easy-to-understand error messages if we attempt to copy or assign a unique_ptr. Write a program that contains these errors to see how your compiler diagnoses them.**

[12.16 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.16%20Solution.cpp)

Two errors:

```cpp
error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]'
     std::unique_ptr<std::string> unique_ptrTwo(unique_ptrOne);
  
error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]'
     std::unique_ptr<std::string> unique_ptrThree = unique_ptrOne;
```

## Exercise 12.17

**Which of the following unique_ptr declarations are illegal or likely to result in subsequent program error? Explain what the problem is with each one.**

```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
```

(a) IntP p0(ix);

Illegal, we cannot use an integer to initialize a `unique_ptr`.

(b) IntP p1(pi);

Can compile but an error will occur. Because the pointer `pi` is not initialized by `new` and memory that `unique_ptr p1` points to will be freed when it is out of scope. Therefore `unique_ptr p1` will try to call `delete` function even though `pi` is not initialized by `new` and an error will occur.

Error message:

Process finished with exit code -1073740940 (0xC0000374)

(c) IntP p2(pi2);

Can compile but will cause a dangling pointer issue. When out of scope, `unique_ptr p2` will try to call `delete` function on pointer `pi2` can free memory that `pi2` points to. However, programmers may still try to use `pi2` which will cause problems.

(d) IntP p3(&ix);

Can compile but an error will occur just like (b).

(e) IntP p4(new int(2048));

Legal.

(f) IntP p5(p2.get());

Illegal, will cause double free problem since two `unique_ptr` point to the same object.

## Exercise 12.18

**Why doesn’t shared_ptr have a release member?**
