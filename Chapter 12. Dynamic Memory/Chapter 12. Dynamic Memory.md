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

Because of the `shared_ptr`, both `b1` and `b2` will have 4 elementsat the end of this code even after `b2` is out of scope.

[12.1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2011.%20Associative%20Containers/Codes/11.3%20Solution.cpp)

