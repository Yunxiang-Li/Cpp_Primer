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

This is illegal. `p.get()` function will return a built-in pointer which also points to where `p` points to. `shared_ptr<int>(p.get())` creates a new `shared_ptr` by the built-in pointer `p.get()`. After `process(shared_ptr<int>(p.get()))`, memory built-in pointer `p.get()` points to will be freed since the function is already executed completely. Because both `shared_ptr<int> p` and built-in pointer `p.get()` points to the same integer thus when user tries to dereference `shared_ptr<int> p`, an undefined behavior occurs.
Even if user does not dereference `shared_ptr<int> p`, when the outer scope ends, `shared_ptr<int> p` will also be freed again which will cause a double free issue.

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
