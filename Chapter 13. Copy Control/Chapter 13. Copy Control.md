# Chapter 13. Copy Control

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
    return *this;
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
    return *this;
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

**Define an `Employee` class that contains an employee name and a unique employee identifier. Give the class a default constructor and a constructor that takes a `string` representing the employee’s name. Each constructor should generate a unique ID by incrementing a static data member.**

[13.18 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.18%20Employee.hpp)

[13.18 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.18%20Employee.cpp)

## Exercise 13.19

**Does your `Employee` class need to define its own versions of the copy-control members? If so, why? If not, why not? Implement whatever copy-control members you think `Employee` needs.**

I think `Employee` class does not need any copy-control members since it is meaningless to copy an `Employee` to another `Employee` object.

[13.19 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.19%20Employee.hpp)

[13.19 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.19%20Employee.cpp)

## Exercise 13.20

**Explain what happens when we copy, assign, or destroy objects of our `TextQuery` and `QueryResult` classes from § 12.3 (p. 484).**

Members (smart pointer and container) will be copied.

## Exercise 13.21

**Do you think the `TextQuery` and `QueryResult` classes need to define their own versions of the copy-control members? If so, why? If not, why not? Implement whichever copy-control operations you think these classes require.**

Synthesized copy-control members are already enough thus no need to define our custom ones.

## Exercise 13.22

**Assume that we want `HasPtr` to behave like a value. That is, each object should have its own copy of the `string` to which the objects point. We’ll show the definitions of the copy-control members in the next section. However, you already know everything you need to know to implement these members. Write the `HasPtr` copy constructor and copy-assignment operator before reading on.**

[13.22 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.22%20HasPtr.hpp)

[13.22 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.22%20HasPtr.cpp)

## Exercise 13.23

**Compare the copy-control members that you wrote for the solutions to the previous section’s exercises to the code presented here. Be sure you understand the differences, if any, between your code and ours.**

It is crucially important for assignment operators to work correctly, even when an object is assigned to itself. A good way to do so is to copy the right-hand operand before destroying the left-hand operand.

## Exercise 13.24

**What would happen if the version of `HasPtr` in this section didn’t define a destructor? What if HasPtr didn’t define the `copy constructor`?**

If `HasPtr` didn't define a destructor, a synthesized destructor will be created but wont release the dynamically allocated memory. Therefore, memory leak will happened.

If `HasPtr` didn't define the copy constructor, when copy constructed, just string's address is copied, the string content witch `ps` points to wont be copied.

## Exercise 13.25

**Assume we want to define a version of `StrBlob` that acts like a value. Also assume that we want to continue to use a `shared_ptr` so that our `StrBlobPtr` class can still use a `weak_ptr` to the `vector`. Your revised class will need a copy constructor and copy-assignment operator but will not need a destructor. Explain what the copy constructor and copy-assignment operators must do. Explain why the class does not need a destructor.**

Copy constructor and copy-assignment operator will dynamically allocate memory to create their own member objects, rather than share objects with right hand operand.

The reason the class does not need a destructor is that `StrBlob` class uses smart pointers which can help free the dynamically allocated memoryautomatically.

## Exercise 13.26

**Write your own version of the StrBlob class described in the previous exercise.**

[13.26 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.26%20StrBlob.hpp)

[13.26 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.26%20StrBlob.cpp)

## Exercise 13.27

**Define your own reference-counted version of `HasPtr`.**

[13.27 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.27%20HasPtr.hpp)

[13.27 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.27%20HasPtr.cpp)

## Exercise 13.28

**Given the following classes, implement a default constructor and the necessary copy-control members.**

Here I change `int count` to `int* count`

(a)

```cpp
class TreeNode {
 private:
  std::string value;
  int*         count;
  TreeNode    *left;
  TreeNode    *right;
};
```

(b)

```cpp
class BinStrTree { 
 private: 
  TreeNode *root;
};
```

[13.28 TreeNode Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.28%20TreeNode.hpp)

[13.28 TreeNode Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.28%20TreeNode.cpp)

[13.28 BinStrTree Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.28%20BinStrTree.hpp)

[13.28 BinStrTree Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.28%20BinStrTree.cpp)

## Exercise 13.29

**Explain why the calls to `swap` inside `swap(HasPtr&, HasPtr&)` do not cause a recursion loop.**

Because `swap(lhs.ps, rhs.ps)` will call `std::swap(std::string*, std::string*)` function and `swap(lhs.i, rhs.i)`  will call `std::swap(int, int)` function. However, function `swap(HasPtr&, HasPtr&)` is our custom function which takes 2 reference of `HasPtr` object thus `swap` calls inside do not cause a recursion loop.

## Exercise 13.30

**Write and test a `swap` function for your valuelike version of `HasPtr`. Give your `swap` a print statement that notes when it is executed.**

[13.30 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.30%20HasPtr.hpp)

[13.30 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.30%20HasPtr.cpp)

## Exercise 13.31

**Give your class a `<` operator and define a `vector` of `HasPtrs`. Give that vector some elements and then `sort` the `vector`. Note when `swap` is called.**

[13.31 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.31%20HasPtr.hpp)

[13.31 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.31%20HasPtr.cpp)

[13.31 Main](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.31%20main.cpp)

## Exercise 13.32

**Would the pointerlike version of `HasPtr` benefit from defining a `swap` function? If so, what is the benefit? If not, why not?**

For the pointerlike version, no dynamic memory allocation needed. Therefore, a specific version for it will not improve the performance.

## Exercise 13.33

**Why is the parameter to the `save` and `remove` members of `Message` a `Folder&`? Why didn’t we define that parameter as `Folder`? Or `const Folder&`?**

Because `save` and `remove` operations will modify the given `Folder` argument thus we cannot define as `const Folder&` which prohibits updating. Moreover, if we define as `Folder` then we will only update the copy, when function calls end, original `Folder` objects are not modified.

## Exercise 13.34

**Write the `Message` class as described in this section.**

See Exercise 13.37

## Exercise 13.35

**What would happen if `Message` used the synthesized versions of the copy-control members?**

Default synthesized versions of the copy-control members cannot update `Message` and `Folder` objects correctly. For instance, synthesized copy constructor will not bind the new `Message` object's content to each relavant `Folder` objects. Moreover, synthesized copy assignment operator will neither remove left `Message` object's content from its binding `Folder` objects nor add right `Message` object's content.

## Exercise 13.36

**Design and implement the corresponding `Folder` class. That class should hold a `set` that points to the `Messages` in that `Folder`.**

See Exercise 13.37

## Exercise 13.37

**Add members to the `Message` class to insert or remove a given `Folder*` into `folders`. These members are analogous to `Folder`’s `addMsg` and `remMsg` operations.**

[13.37 Message Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.37%20Message.hpp)

[13.37 Message Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.37%20Message.cpp)

[13.37 Folder Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.37%20Folder.hpp)

[13.37 Folder Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.37%20Folder.cpp)

[13.37 Main](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.37%20main.cpp)

## Exercise 13.38

**We did not use copy and swap to define the `Message` assignment operator. Why do you suppose this is so?**

`Message` class's custom `swap` function needs to remove both `Message` object's old binding relations and then add both `Message` object's new binding relations, which is nearly twice inefficient as normal copy assignment operator function. Therefore, there is no need to combine `copy` and `swap` together to define the `Message` class's copy assignment operator.

## Exercise 13.39

**Write your own version of `StrVec`, including versions of `reserve`, `capacity` (§ 9.4, p. 356), and `resize` (§ 9.3.5, p. 352).**

[13.39 StrVec Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.39%20StrVec.hpp)

[13.39 StrVec Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.39%20StrVec.cpp)

## Exercise 13.40

**Add a constructor that takes an `initializer_list<string>` to your `StrVec` class.**

[13.40 StrVec Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.40%20StrVec.hpp)

[13.40 StrVec Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.40%20StrVec.cpp)

## Exercise 13.41

**Why did we use postfix increment in the call to `construct` inside `push_back`? What would happen if it used the prefix increment?**

Because postfix will ensure that first element will be placed at first vacant place(where `m_elements` points to).

If we use prefix increment without any more modifications, then first element will be placed at second vacant place(one element after `m_elements` points to). Therefore, one vacant place is ignored which may cause issues later.

## Exercise 13.42

**Test your `StrVec` class by using it in place of the `vector<string>` in your `TextQuery` and `QueryResult` classes (§ 12.3, p. 484).**

`StrVec` class is same as Exercise 13.40

[13.42 TextQuery Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.42%20TextQuery.hpp)

[13.42 TextQuery Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.42%20TextQuery.cpp)

[13.42 QueryResult Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.42%20QueryResult.hpp)

[13.42 QueryResult Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.42%20QueryResult.cpp)

[13.42 Test](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.42%20main.cpp)

## Exercise 13.43

**Rewrite the `free` member to use `for_each` and a lambda (§ 10.3.2, p. 388) in place of the `for` loop to destroy the elements. Which implementation do you prefer, and why?**

Old version(`for` loop):
```cpp
void StrVec::m_free() {
    if (m_elements) {
        for (std::string* ptr = m_first_free; ptr != m_elements;)
            alloc.destroy(--ptr);
        alloc.deallocate(m_elements, m_capacity());
    }
}
```

New version(`for_each` and a lambda):
```cpp
void StrVec::m_free() {
    if (m_elements)
        std::for_each(m_elements, m_first_free, [](std::string& eachStr){alloc.destroy(&eachStr);});
    alloc.deallocate(m_elements, m_capacity());
}
```

I prefer new version since we do not need to care about prefix/postfix and order issues.

## Exercise 13.44

**Write a class named `String` that is a simplified version of the library `string` class. Your class should have at least a default constructor and a constructor that takes a pointer to a C-style string. Use an `allocator` to allocate memory that your `String` class uses.**

[13.44 String Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.44%20String.hpp)

[13.44 String Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.44%20String.cpp)

## Exercise 13.45

**Distinguish between an rvalue reference and an lvalue reference.**

lvalue reference: reference that can bind to an lvalue. (Regular reference)

rvalue reference: reference to an object that is about to be destroyed.

I usually memorize lvalue as having address and rvalue as not having address.

## Exercise 13.46

**Which kind of reference can be bound to the following initializers?**

```cpp
int f();

vector<int> vi(100);

int? r1 = f(); 

int& r2 = vi[0];

int& r3 = r1;

int&& r4 = vi[0] * f();
```

Solution:

```cpp
// f() return a temporary integer which is a rvalue.
int&& r1 = f(); 

// Subscript result is a lvalue.
int& r2 = vi[0];

// A non-temporary variable is a lvalue.
int& r3 = r1;

// The result of an expression multiplication is a temporary integer which is a rvalue
int&& r4 = vi[0] * f();
```

## Exercise 13.47

**Give the copy constructor and copy-assignment operator in your `String` class from exercise 13.44 in § 13.5 (p. 531) a statement that prints a message each time the function is executed.**

[13.47 String Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.44%20String.hpp)(Same as Exercise 13.44)

[13.47 String Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.47%20String.cpp)

## Exercise 13.48

**Define a `vector<String>` and call `push_back` several times on that `vector`. Run your program and see how often `Strings` are copied.**

`String` class is same as Exercise 13.47

[13.48 Test](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.48%20main.cpp)

## Exercise 13.49

**Add a move constructor and move-assignment operator to your `StrVec`, `String`, and `Message` classes.**

`StrVec` : [13.49 StrVec Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.49%20StrVec.hpp) | [13.49 StrVec Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.49%20StrVec.cpp)

`String` : [13.49 String Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.49%20String.hpp) | [13.49 String Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.49%20String.cpp)

`Folder` : [13.49 Folder Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.49%20Folder.hpp) | [13.49 Folder Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.49%20Folder.cpp)

`Message` : [13.49 Message Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.49%20Message.hpp) | [13.49 Message Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.49%20Message.cpp)

## Exercise 13.50

**Put print statements in the move operations in your `String` class and rerun the program from exercise 13.48 in § 13.6.1 (p. 534) that used a `vector<String>` to see when the copies are avoided.**

My program avoids copy constructor once(Use move constructor instead) and copy assignment once(Use move assignment instead).

Test program: same as exercise 13.48

`StrVec` : Header is same as exercise 13.49 | [13.50 StrVec Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.50%20String.cpp)

## Exercise 13.51

**Although `unique_ptrs` cannot be copied, in § 12.1.5 (p. 471) we wrote a `clone` function that returned a `unique_ptr` by value. Explain why that function is legal and how it works.**

```cpp
unique_ptr<int> clone(int p) {
    // ok: explicitly create a unique_ptr<int> from int*
    return unique_ptr<int>(new int(p));
}
```

Because the result of `clone` is a rvalue thus it uses the move-assignment operator instead of copy-assignment operator. Therefore, it is legal and can work.

## Exercise 13.52

**Explain in detail what happens in the assignments of the `HasPtr` objects on page 541. In particular, describe step by step what happens to values of `hp`, `hp2`, and of the `rhs` parameter in the `HasPtr` assignment operator.**

```cpp
class HasPtr {
  public:
    // added move constructor    
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {p.ps = 0;}
    // assignment operator is both the move- and copy-assignment operator
    HasPtr& operator=(HasPtr rhs){
      swap(*this, rhs);
      return *this;
    }   
    // other members as in § 13.2.1 (p. 511)
};

hp = hp2; //  hp2 is an lvalue;copy constructor used to copy hp2
hp = std::move(hp2); // move constructor moves hp2
```

The assignment operator has a nonreference parameter `rhs`, which means the parameter is copy initialized. Depending on the type of the argument, copy initialization uses either the copy constructor or the move constructor. lvalues are copied and rvalues are moved. 

`hp = hp2;` : the copy-assignment operator is called. First, `hp2`'s(`rhs`'s) data members are copyed and stored in an intermediate object. Then, `hp2`'s(`rhs`'s) data members are deleted. Finally, the copyed data members in the intermediate object are assigned to `hp`.

`hp = std::move(hp2);` : the move-assignment operator is called. First, `std::move()` return the rvalue reference of `hp2`. Second, the data members of the `hp2`(`rhs`) are moved to `hp1`. Finally, `hp2`(`rhs`) is in a valid state which can be then safely used or destroyed .

## Exercise 13.53

**As a matter of low-level efficiency, the `HasPtr` assignment operator is not ideal. Explain why. Implement a copy-assignment and move-assignment operator for `HasPtr` and compare the operations executed in your new move-assignment operator versus the copy-and-swap version.**

According to exercise 13.52, if we want to use a single assignment operator to solve both situations: `HasPtr& operator=(HasPtr rhs);`. No matter the copy-assignment operator is called or the copy-assignment operator is called, argument `rhs` is always passed by value(copy initialized) which is less efficient if `HasPtr` is very large and has many members to copy.

Therefore we should implement two assignment operators: `HasPtr& operator=(const HasPtr& rhs)` for copy assignment and `HasPtr& operator=(const HasPtr& rhs);` for move assignment

[13.53 HasPtr Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.53%20HasPtr.hpp)

[13.53 HasPtr Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.53%20HasPtr.cpp)

## Exercise 13.54

**What would happen if we defined a `HasPtr` move-assignment operator but did not change the copy-and-swap operator? Write code to test your answer.**

Here is my result:

```cpp
// Error, `operator=` is ambiguous.
error: ambiguous overload for 'operator=' 
(operand types are 'HasPtr' and 'std::remove_reference<HasPtr&>::type' {aka 'HasPtr'}) hp1 = std::move(hp4);
```

[13.54 HasPtr Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.54%20HasPtr.hpp)

[13.54 HasPtr Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.54%20HasPtr.cpp)

[Test](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.54%20main.cpp)

## Exercise 13.55

**Add an rvalue reference version of `push_back` to your `StrBlob`.**

[13.55 StrBlob Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.55%20StrBlob.hpp)

[13.55 StrBlob Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.55%20StrBlob.cpp)

## Exercise 13.56

**What would happen if we defined `sorted` as:**

```cpp
Foo Foo::sorted() const & {
  Foo ret(*this);
  return ret.sorted();
}
```

Local `Foo` object `ret` here is a lvalue thus `ret.sorted` will call `Foo sorted() const &` instead of `Foo sorted() &&`. Therefore, the result will be a forever dead loop.

## Exercise 13.57

**What would happen if we defined `sorted` as:**

```cpp
Foo Foo::sorted() const & { return Foo(*this).sorted(); }
```

`Foo(*this)` is a rvalue thus `Foo(*this).sorted()` will call `Foo sorted() &&` instead of `Foo sorted() const &`. We create a temporary `Foo` object as current `Foo` object's copy and run move version of `sorted` function on it to get a new lvalue result.

## Exercise 13.58

**Write versions of class `Foo` with print statements in their `sorted` functions to test your answers to the previous two exercises.**

[13.58 Foo Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.58%20Foo.hpp)

[13.58 Foo Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.58%20Foo.cpp)

[13.58 Main](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2013.%20Copy%20Control/Codes/13.58%20main.cpp)
