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

Pros:

The compiler will not use this constructor in an automatic conversion thus it is more clear for programmers.

Cons:

When using the constructor with a single parameter, the compiler cannot convert a single input variable to be the right type for that constructor.
