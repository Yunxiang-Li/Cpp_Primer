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
Point foo_bar(Point arg) // 1. Copy constructor is called here once to create an input Point instance arg.
{
  // 2-3. Copy constructor is called here twice: 1. Copy arg to initialize local
  // 2. Create a new Point instance by the copy constructor
  Point local = arg, *heap = new Point(global); 
  *heap = local;
  // 4-5. Copy constructor is called here twice: brace initialization of a Point array.
  // First two elements are local and *heap, next two elements are 2 default Point instances.
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

## Exercise 13.6

**What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?**

The **copy-assignment operator** is a non-template non-static member function with the name `operator=`.

This operator is used when assignment occurred.

The synthesized **copy-assignment operator** assigns each non-static member of the right-hand operand(object) to corresponding member of the left-hand operand(object) using the **copy-assignment operator** for the type of that member.

It is synthesized when the class does not define its own **copy-assignment operator**.

## Exercise 13.7

**What happens when we assign one `StrBlob` to another? What about `StrBlobPtrs`?**

In both situations, only shallow copy will occur as all pointers point to the same address. The use_count changed the same as exercise 13.3.

## Exercise 13.8

**Write the assignment operator for the `HasPtr` class from exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your assignment operator should copy the object to which `ps` points.**

Here is my solution:

```cpp
class HasPtr
{
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
  
  HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
  
  HasPtr& operator=(const HasPtr& hp) 
  {
    std::string* newStr = new std::string(*hp.ps);
    delete this -> ps;
    this -> ps = newStr;
    this -> i = hp.i;
    return this;
  }

private:    
  std::string *ps;
  int    i;
};
```

## Exercise 13.9

**What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?**

A destructor is a special member function that is called when the lifetime of an object ends. 

The purpose of the synthesized destructor is to free resources that the object may have acquired during its lifetime.

The compiler creates a synthesized destructor for any class that does not define its own destructor.

## Exercise 13.10

**What happens when a StrBlob object is destroyed? What about a StrBlobPtr?**

When a **StrBlob** object destroyed, the `use_count` of the dynamic object will decrement. It will be freed if the reference count of that dynamic object is zero.

When a **StrBlobPter** object is destroyed the object dynamically allocated will not be freed until we call `delete`/`delete[]`.

## Exercise 13.11

**Add a destructor to your HasPtr class from the previous exercises.**

Here is my solution:

```cpp
class HasPtr
{
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
  
  HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
  
  HasPtr& operator=(const HasPtr& hp) 
  {
    std::string* newStr = new std::string(*hp.ps);
    delete this -> ps;
    this -> ps = newStr;
    this -> i = hp.i;
    return this;
  }
  
  ~HasPtr() 
  {
    delete this -> ps;
  }

private:    
  std::string *ps;
  int    i;
};
```

## Exercise 13.12

**How many destructor calls occur in the following code fragment?**

```cpp
bool fcn(const Sales_data *trans, Sales_data accum)
{
  Sales_data item1(*trans), item2(accum);
  return item1.isbn() != item2.isbn();
}
```

Altogether the destructor of `Sales_data` class is called 3 times. One for `item1`, one for `item2` and one for `accum`.
Here `trans` is a pointer to a `Sales_data` instance which will not be freed by the destructor autimatically.

## Exercise 13.13

**A good way to understand copy-control members and constructors is to define a simple class with these members in which each member prints its name:**

```cpp
struct X 
{
  X() 
    {
      std::cout << "X()" << std::endl;
    }    
  X(const X&) 
    {
      std::cout << "X(const X&)" << std::endl;
    }
};
```
**Add the copy-assignment operator and destructor to X and write a program using X objects in various ways: Pass them as nonreference and reference parameters; dynamically allocate them; put them in containers; and so forth. Study the output until you are certain you understand when and why each copy-control member is used. As you read the output, remember that the compiler can omit calls to the copy constructor.**

[13.13 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.13%20Solution.cpp)

My output:

```cpp
X()
X(const X&)
(const X&)
X(const X&)
X(const X&)
~X()
~X()
~X()
~X()
~X()
```

## Exercise 13.14

**Assume that `numbered` is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named `mysn`. Assuming `numbered` uses the synthesized copy-control members and given the following function:**

```cpp
void f (numbered s) { cout << s.mysn << endl; }
```

**what output does the following code produce?**

```cpp
numbered a, b = a, c = b;
f(a); f(b); f(c);
```

The output will be 3 identical serial numbers. `a` is created by the default constructor, `b` and `c` are created by the synthesized copy constructor.

## Exercise 13.15

**Assume `numbered` has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?**

Yes, the output will be changed because custom copy constructor will generate 3 different serial numbers for `a`, `b` and `c`.

Moreover, `void f (numbered s) { cout << s.mysn << endl; }` here will also call the custom copy constructor once for each function call since here argument is passed by value.

Altogether the custom copy constructor will be called 5 times(2 for constructing `b` and `c`, 3 when passing `a`, `b` and `c` into function `f` by value).

## Exercise 13.16

**What if the parameter in `f` were `const numbered&`? Does that change the output? If so, why? What output gets generated?**

Yes, the output will be changed(still 3 different serial numbers) because `void f (const numbered& s) { cout << s.mysn << endl; }` here argument is passed by reference thus copy constructor will not be called when `f` function is called.

Altogether the custom copy constructor will be called 2 times(For constructing `b` and `c`).

## Exercise 13.17

**Write versions of numbered and f corresponding to the previous three exercises and check whether you correctly predicted the output.**

[13.14 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.14%20Solution.cpp)

[13.15 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.15%20Solution.cpp)

[13.16 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.16%20Solution.cpp)

## Exercise 13.18

**Define an `Employee` class that contains an employee name and a unique employee identifier. Give the class a default constructor and a constructor that takes a string representing the employee’s name. Each constructor should generate a unique ID by incrementing a static data member.**

[13.18 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.18%20Employee.hpp)

[13.18 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.18%20Employee.cpp)
