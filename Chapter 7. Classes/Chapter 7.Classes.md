# Chapter 7.Classes

## Exercise 7.1

**Write a version of the transaction-processing program from § 1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).**

[Sales_data.h](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%202.%20Variables%20and%20Basic%20Types/Codes/2.42%20Sales_data.h)

[7.1 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.1%20Solution.cpp)

## Exercise 7.2

**Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).**

[7.2 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.2%20Solution.hpp)

## Exercise 7.3

**Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.**

[7.3 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.3%20Solution.cpp)

## Exercise 7.4

**Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.**

[7.4 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.4%20Solution.cpp)

## Exercise 7.5

**Provide operations in your Person class to return the name and address. Should these functions be const? Explain your choice.**

[7.5 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.5%20Solution.cpp)

## Exercise 7.6

**Define your own versions of the add, read, and print functions.**

[7.6 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.6%20Solution.hpp)

## Exercise 7.7

**Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.**

[7.7 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.7%20Solution.cpp)

## Exercise 7.8

**Why does read define its Sales_data parameter as a plain reference and print define its parameter as a reference to const?**

Define `read`'s `Sales_data` parameter as plain reference since it intended to change the revenue's value.

Define `print`'s `Sales_data` parameter as a reference to const since it did not intend to change any member's value of this object.

## Exercise 7.9

**Add operations to read and print Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).**

[7.9 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.9%20Solution.hpp)

## Exercise 7.10

**What does the condition in the following if statement do?**

```cpp
if (read(read(cin, data1), data2))
```

This line of codes work like this:

```cpp
std::istream &firstIstream = read(cin, data1);
std::istream &secondIstream = read(firstStep, data2);
if (secondIstream)
```

Inner `read` function first reads and stores `data1`'s members into a `std::istream` object. Outer `read` function then reads and stores the `data2`'s memebers into the same `std::istream` object.

The condition of the if statement checks whether the result `std::istream` object is empty or not after trying to read and store `data1` and `data2`'s members.

## Exercise 7.11

**Add constructors to your Sales_data class and write a program to use each of the constructors.**

[7.11 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.11%20Solution.hpp)

[7.11 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.11%20Solution.cpp)

## Exercise 7.12

**Move the definition of the Sales_data constructor that takes an istream into the body of the Sales_data class.**

[7.12 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.12%20Solution.hpp)

## Exercise 7.13

**Rewrite the program from page 255 to use the istream constructor.**

[7.13 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.13%20Solution.cpp)

## Exercise 7.14

**Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.**

```cpp
Sales_data() : units_sold(0) , revenue(0){}
```

## Exercise 7.15

**Add appropriate constructors to your Person class.**

[7.15 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.15%20Solution.hpp)

## Exercise 7.16

**What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?**

There are no constraints on where and how often an access specifier may appear.The specified access level remains in effect until the next access specifier or the end of the class body.

The members which are accessible to all parts of the program should be defined inside a public specifier.

The members which are accessible to the member functions of the class but are not accessible to code that uses the class should be defined inside a private specifier.

## Exercise 7.17

**What, if any, are the differences between using class or struct?**

A class's default access level is private and a struct's default access level is public.

## Exercise 7.18

**What is encapsulation? Why is it useful?**

Encapsulation is the separation of implementation from interface. It hides the implementation details of a type. 

It is useful because:
1. User code cannot inadvertently corrupt the state of an encapsulated object.
2. The implementation of an encapsulated class can change over time without requiring changes in user-level code.

## Exercise 7.19

**Indicate which members of your Person class you would declare as public and which you would declare as private. Explain your choice.**

I will declare `constructors, getName(), getAddress()` as public and declare members `name, address` as private.

I do not want users to have direct access to class members since users may modify each member's value which is not what we want. Instead we will provide appropriate access functions(such as `getName` and `getAddress`) to enable users to get what they want but not modify original values.

## Exercise 7.20

**When are friends useful? Discuss the pros and cons of using friends.**

Pros:

1. Users can use friend functions to access class members without specifying the class name.

2. Users can access all non-public class members easily.

3. Programmers can use friends to help test all private members of the class.

Cons:

1. Decrease codes' encapsulation, maintainability and verbosity.

2. Sometimes it may be a bad idea to let users have opportunities to private class members.

## Exercise 7.21

**Update your Sales_data class to hide its implementation. The programs you’ve written to use Sales_data operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.**

[7.21 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.21%20Solution.hpp)

## Exercise 7.22

**Update your Person class to hide its implementation.**

[7.22 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.22%20Solution.hpp)

## Exercise 7.23

**Write your own version of the Screen class.**

[7.23 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.23%20Solution.hpp)

## Exercise 7.24

**Give your Screen class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.**

[7.24 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.24%20Solution.hpp)

## Exercise 7.25

**Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?**

Yes. Because we have already initialized all other class members of built-in type. And `std::string` type itself can rely on the default versions of copy and assignment.

Therefore our Screen class can rely on the default versions of copy and assignment.

## Exercise 7.26

**Define Sales_data::avg_price as an inline function.**

[7.26 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.26%20Solution.hpp)

[7.26 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.26%20Solution.cpp)

## Exercise 7.27

**Add the move, set, and display operations to your version of Screen. Test your class by executing the following code:**

```cpp
Screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

[7.27 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.27%20Solution.hpp)

[7.27 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.27%20Solution.cpp)

[7.27 Test](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.27%20main.cpp)

## Exercise 7.28

**What would happen in the previous exercise if the return type of move, set, and display was Screen rather than Screen&?**

If the return type of `move`, `set`, and `display` was `Screen` rather than `Screen&`, then `set('#')` and `display(cout)` of `myScreen.move(4,0).set('#').display(cout);` only works on a temporary copy of `myScreen` thus `myScreen` itself remains no changes after being initialized by `Screen myScreen(5, 5, 'X');`.

The result will be like:

```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

## Exercise 7.29

**Revise your Screen class so that move, set, and display functions return Screen and check your prediction from the previous exercise.**

[7.29 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.29%20Solution.hpp)

[7.29 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.29%20Solution.cpp)

[7.29 Test](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.29%20main.cpp)

1. The result when return type of `move`, `set`, and `display` was `Screen&`:

```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
```

2. The result when return type of `move`, `set`, and `display` was `Screen`:

```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

## Exercise 7.30

**It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the this pointer to access members.**

Pros:

1. More explicit for programmers to know that the specified name is a member name.
2. By refering to members through the this pointer, the member function's parameters are allowed to be same as the member names.

For instance:

```cpp
void setStr(const std::string& str1, const std::string& str2) 
{
  this -> str1 = str1;
  this -> str2 = str2;
}
```

Cons:

1. More letters to read which may be redundant.
2. Sometimes unnecessary to refering to members through the this pointer.

For instance:

```cpp
const std::string& getStr() const 
{
  return this -> str1;
}
```

## Exercise 7.31

**Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.**

[7.31 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.31%20Solution.hpp)

## Exercise 7.32

**Define your own versions of Screen and Window_mgr in which clear is a member of Window_mgr and a friend of Screen.**

[7.32 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.32%20Solution.hpp)

## Exercise 7.33

**What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.**

```cpp
pos Screen::size() const
{
  return height * width;
}
```

The `pos` type is only defined in the scope of `Screen` class thus the compiler does not know what `pos` actually is and where it exists which will cause an error.

To fix this, we should use `Screen::pos` instead of `pos` so that the compiler will know where to find that `pos` type(in the `Screen` class).

## Exercise 7.34

**What would happen if we put the typedef of pos in the Screen class on page 285 as the last line in the class?**

The compiler will throw an error: 

```cpp
Unknown type name 'pos'
```

This is because the compiler only try to find the typedef of `pos` before the first use of `pos`. If cannot find, then throw the error.


## Exercise 7.35

**Explain the following code, indicating which definition of Type or initVal is used for each use of those names. Say how you would fix any errors.**

```cpp
typedef string Type;
Type initVal(); // Type here is string.

class Exercise {
public:    
  typedef double Type; 
  Type setVal(Type); // Both Type here are double.
  Type initVal(); // Type here is double.
private:
  int val;
};

Type Exercise::setVal(Type parm) {  // First Type here is string. Second Type is double.
  val = parm + initVal();
  return val;
}
```

First `Type` in `Type Exercise::setVal(Type parm)` is string because no scope specified thus treat as ::Type(global scope) which may not programmers want.

Fixed version:

```cpp
typedef string Type;
Type initVal(); 

class Exercise {
public:    
  typedef double Type; 
  Type setVal(Type); 
  Type initVal(); 
private:
  int val;
};

// We specify first Type's scope(in the Exercise class scope).
Exercise::Type Exercise::setVal(Type parm) { 
  val = parm + initVal();
  return val;
}
```

## Exercise 7.36

**The following initializer is in error. Identify and fix the problem.**

```cpp
struct X {
  X (int i, int j): base(i), rem(base % j) { } 
  int rem, base;
};
```

According to the struct `X`, `rem` is declared before `base` thus the compiler will try to initialize `rem` with `base % j` first.

However, at this time `base` is not initialized yet, thus `rem` cannot be initialized correctly(`rem` will have an undefined value).

Fixed version:

```cpp
struct X {
  X (int i, int j): base(i), rem(base % j) { } 
  int base, rem;
};
```

## Exercise 7.37

**Using the version of Sales_data from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:**

```cpp
// Use Sales_data(std::istream &is) constructor, member values are determined by user's input.
Sales_data first_item(cin);

int main() {
  // Use Sales_data(std::string s = "") as the default constructor. Here bookNo = "", cnt = 0 and revenue = 0.0.
  Sales_data next;
  // Use Sales_data(std::string s = "") as the single parameter constructor.
  // Here bookNo = "9-999-99999-9", cnt = 0 and revenue = 0.0.
  Sales_data last("9-999-99999-9");
}
```

## Exercise 7.38

**We might want to supply cin as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument.**

```cpp
Sales_data(std::istream &is = std::cin) {
  read(is, *this);
}
```

## Exercise 7.39

**Would it be legal for both the constructor that takes a string and the one that takes an istream& to have default arguments? If not, why not?**

No, it is illegal to do so. Because if so, when user uses default constructor to constructs a class, the compiler will not know which constructor it should use since both constructos(the constructor with `string` parameter and the constructor with `istream&` parameter) fit the requirement. 

## Exercise 7.40

**Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.**

(a) Book

(b) Date

(c) Employee

(d) Vehicle

(e) Object

(f) Tree

[7.40 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.40%20Solution.hpp)

## Exercise 7.41

**Rewrite your own version of the Sales_data class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a Sales_data object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.**

[7.41 Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.41%20Solution.hpp)

[7.41 Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.41%20Solution.cpp)

[7.41 Test](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.41%20main.cpp)

## Exercise 7.42

**For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.**

[7.42 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.42%20Solution.hpp)

## Exercise 7.43

**Assume we have a class named NoDefault that has a constructor that takes an int, but has no default constructor. Define a class C that has a member of type NoDefault. Define the default constructor for C.**

[7.43 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.43%20Solution.cpp)

## Exercise 7.44

**Is the following declaration legal? If not, why not?**

```cpp
vector<NoDefault> vec(10);
```

This declaration is illegal. Here we are trying to initialize a `vector` of 10 `NoDefault` objects and each `NoDefault` object should be initialized by the single argument constructor since no default constructor is provided. However, `vec(10)` here only specifies the vector's size but not each `NoDefault` object's initialized value thus this declaration is illegal since each `NoDefault` object's initialized value is undefined.

## Exercise 7.45

**What if we defined the vector in the previous execercise to hold objects of type C?**

This is legal. Because in class `C`, constructor of `C` will initialize each `Nodefault` member object by `C() : def(NoDefault(0)) {}`.

## Exercise 7.46

**Which, if any, of the following statements are untrue? Why?**

(a) A class must provide at least one constructor.

Untrue. It is not necessary for a class to provide at least one constructor since the compiler will create a default constructor for us if no other constructors are found.

(b) A default constructor is a constructor with an empty parameter list.

Untrue. A default constructor is not only a constructor with an empty parameter list but also a constructor with default arguments provided for every parameter. A constructor with member initialize list is not a default constructor.

(c) If there are no meaningful default values for a class, the class should not provide a default constructor.

Untrue. Usually we should always provide a default constructor if other constructors are being defined even if there are no meaningful default values for the class. This action will help us in many other aspects(For instance, we can use vector to hold this class's objects with initialized values easily and we can use another class which holds this class's object as a member to generate a synthesized constructor easily)

(d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

Untrue. The default constructor is auto-generated if there is no user-declared constructor and each data member is not initialized to the default value. 

## Exercise 7.47

**Explain whether the Sales_data constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?**

Whether the conversion of a string to `Sales_data` is desired depends on how we think our users will use the conversion. In this case, it might be okay. The string in `null_book` probably represents a nonexistent ISBN.

Benefits:

- prevent the use of a constructor in a context that requires an implicit conversion
- we can define a constructor which is used only with the direct form of initialization

Drawbacks:

- meaningful only on constructors that can be called with a single argument

## Exercise 7.48

**Assuming the Sales_data constructors are not explicit, what operations happen during the following definitions**

```cpp
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```

First the string `null_isbn` with value `9-999-99999-9` is defined. Next, a `Sales_data` object `item1` is constructed by the string `null_isbn` according to the one string argument constructor. Then, another `Sales_data` object `item2` is constructed by the string literal `9-999-99999-9`(a `const char*` type). This time string literal `9-999-99999-9` is first converted to a temporary string and then `item2` is constructed in the way just like `item1`.

## Exercise 7.49

**For each of the three following declarations of combine, explain what happens if we call i.combine(s), where i is a Sales_data and s is a string:**

```cpp

(a) Sales_data &combine(Sales_data);

(b) Sales_data &combine(Sales_data&);

(c) Sales_data &combine(const Sales_data&) const;

```

(a) Legal. `s` is first converted to a temporary `Sales_data` object by the one string argument constructor and then the `combine` action execute.

(b) Illegal. Cannot convert `std::string` type to `Sales_data&` type (According to C++ design, binding a temporary to a non-const reference is meaningless and now allowed).

(c) Illegal. `Sales_data &combine(const Sales_data&)` part works(According to C++ design, binding a temporary to a const reference is allowed). However, the trailing const mark can't be put here since the `combine` method will modify the `Sales_data` object's members.

## Exercise 7.50

**Determine whether any of your Person class constructors should be explicit.**

[7.50 Solution](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%207.%20Classes/Codes/7.50%20Solution.hpp)
