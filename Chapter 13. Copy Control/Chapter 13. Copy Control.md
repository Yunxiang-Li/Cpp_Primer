# Chapter 13. Copy Control.md

## Exercise 13.1

**What is a copy constructor? When is it used?**

A copy constructor is a constructor which first parameter is a **const reference** to the class type and any additional parameters(if exist) have **default values**.

When copy initialization happens, either the copy constructor or the move constructor is called.

Copy constructor is used when:

- Define variables using an `=`
- Pass an object as an argument to a parameter of non-reference type
- Return an object from a function that has a non-reference return type
- Brace initialize the elements in an array or the members of an aggregate class
- Some class types also use copy initialization for the objects they allocate.

## Exercise 13.2

**Explain why the following declaration is illegal:**

```cpp
Sales_data::Sales_data(Sales_data rhs);
```

If the copy constructor declaration is like this, the call will loop forever. Because `Sales_data rhs` is a non-reference parameter, thus, we'd need to use the copy constructor of class `Sales_data` to copy the input argument, which we'd need to call the copy constructor again and again, and so on indefinitely.

## Exercise 13.3

**What happens when we copy a StrBlob? What about StrBlobPtrs?**

when we copy a `StrBlob`, the **shared_ptr** member's use_count add one.

when we copy a `StrBlobPrts`, the **weak_ptr** member's use_count isn't changed.

## Exercise 13.4

**Assuming `Point` is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:**

Altogether, the `Point` class's copy constructor is called 6 times.

```cpp
Point global;
Point foo_bar(Point arg) // 1. Copy constructor is called here to assign the input argument
{
  // 2-3. Copy constructor is called here twice: 1. Copy arg to initialize local 2. Create a new Point instance by the copy constructor
  Point local = arg, *heap = new Point(global); 
  *heap = local;
  // 4-5. Copy constructor is called here twice: brace initialization of a Point array. First two elements are local and *heap, next two elements are 2 default Point instances.
  Point pa[ 4 ] = { local, *heap }; 
  // 6. Copy constructor is called here once to create the return value(a Point class).
  return *heap;
}
```

## Exercise 13.5

**Given the following sketch of a class, write a copy constructor that copies all the members. Your constructor should dynamically allocate a new string (§ 12.1.2, p. 458) and copy the object to which ps points, rather than copying ps itself.**

```cpp
class HasPtr
{
public:
  HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) { }

private:    
  std::string *ps;
  int    i;
};
```

Here is my solution:

```cpp
class HasPtr
{
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
  HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}

private:    
  std::string *ps;
  int    i;
};
```

[13.5 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2012.%20Dynamic%20Memory/Codes/12.2%20Solution.hpp)
