# Chapter 15. Object-Oriented Programming

## Exercise 15.1

**What is a virtual member?**

A virtual member is a member function in a base class expects its derived class to override and define its own version. Whether to call the member function in base class or in derived class depends on dynamic binding. 

In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 15.2

**How does the protected access specifier differ from private?**

base class members:

`private`: Only base class itself and its friends can access.

`protected`: Base class itself, its friends and all derived classes can access.

## Exercise 15.3

**Define your own versions of the `Quote` class and the `print_total` function.**

[15.3 Quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.3%20Quote.hpp)

[15.3 Quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.3%20Quote.cpp)

## Exercise 15.4

**Which of the following declarations, if any, are incorrect? Explain why.**

```cpp
class Base { ... };
(a) class Derived : public Derived { ... }; // Incorrect, a class cannot inherit itself.
(b) class Derived : private Base { ... }; // Correct.
// Incorrect, a derived class is declared like any other class. The declaration should only contain the class name.
(c) class Derived : public Base; 
```

## Exercise 15.5

**Define your own version of the `Bulk_quote` class.**

`Quote` class is same as exercise 15.3.

[15.5 Bulk_quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.5%20Bulk_quote.hpp)

[15.5 Bulk_quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.5%20Bulk_quote.cpp)

## Exercise 15.6

**Test your `print_total` function from the exercises in § 15.2.1 (p. 595) by passing both `Quote` and `Bulk_quote` objects on that function.**

[15.6 Test](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.6%20main.cpp)

## Exercise 15.7

**Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.**

[15.7 Limit_quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.7%20Limit_quote.hpp)

[15.7 Limit_quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.7%20Limit_quote.cpp)

## Exercise 15.8

**Define static type and dynamic type.**

static type: Static type is known at compile time. Its type is just the same as its declaration.

dynamic type: Type of an object at run time. The dynamic type of an object to which a reference refers or to which a pointer points may differ from the static type of the reference or pointer.

## Exercise 15.9

**When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.**

A pointer or reference to a base-class type can refer to an object of derived type. In such cases the static type is a reference (or pointer) to the base class, but the dynamic type is a reference (or pointer) to the derived class.

## Exercise 15.10

**Recalling the discussion from §8.1 (p. 311), explain how the program on page 317 that passed an `ifstream` to the `Sales_data` read function works.**

the function takes an `istream` parameter which means an `istream` object or an object which derived from `istream` class will work. Because the `ifstream` object is a derived class of `istream` class thus it works.

## Exercise 15.11

**Add a virtual `debug` function to your `Quote` class hierarchy that displays the data members of the respective classes.**

[15.11 Quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.11%20Quote.hpp)

[15.11 Quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.11%20Quote.cpp)

[15.11 Bulk_quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.11%20Bulk_quote.hpp)

[15.11 Bulk_quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.11%20Bulk_quote.cpp)

[15.11 Limit_quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.11%20Limit_quote.hpp)

[15.11 Limit_quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.11%20Limit_quote.cpp)

## Exercise 15.12

**Is it ever useful to declare a member function as both `override` and `final`? Why or why not?**

Yes. By adding `override` keyword, the compile to check if this member function override the same name virtual function from the base class. By adding `final` keyword, the compiler will check if there are no attemps to override this virtual function by any derived classes. 

## Exercise 15.13

**Given the following classes, explain each `print` function:**

```cpp
class base {
public:
  string name() { return basename; }
  virtual void print(ostream &os) { os << basename; }
private:
  string basename;
};
class derived : public base {
public:
  void print(ostream &os) { print(os); os << " " << i; }
private:
  int i;
};
```

**If there is a problem in this code, how would you fix it?**

The `base` class wants to print the `basename`, the `derived` class wants to first print the `basename` and then print the `i`.

There is a problem: `print(os)` in `derived` class should call the `print` function from the base class. However here the class scope `base::` was omitted. As a result, it will cause an infinite recursion and call `derived::print` function again and again.

## Exercise 15.14

**Given the classes from the previous exercise and the following objects, determine which function is called at run time:**

```cpp
base bobj; base *bp1 = &bobj; base &br1 = bobj;
derived dobj; base *bp2 = &dobj; base &br2 = dobj;

(a) bobj.print(); // base::print() is called.

(b) dobj.print(); // derived::print() is called.

(c) bp1->name(); // base::name() is called.

(d) bp2->name(); // base::name() is called.

(e) br1.print(); // base::print() is called.

(f) br2.print(); // derived::print() is called.
```

(e) and (f) are called at run time.

## Exercise 15.15

**Define your own versions of `Disc_quote` and `Bulk_quote`.**

`Quote` class is the same as exercise 15.11.

[15.15 Disc_quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.15%20Disc_quote.hpp)

[15.15 Disc_quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.15%20Disc_quote.cpp)

[15.15 Bulk_quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.15%20Bulk_quote.hpp)

[15.15 Bulk_quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.15%20Bulk_quote.cpp)

## Exercise 15.16

**Rewrite the class representing a limited discount strategy, which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from `Disc_quote`.**

[15.16 Limit_quote Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.16%20Limit_quote.hpp)

[15.16 Limit_quote Source](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.16%20Limit_quote.cpp)

## Exercise 15.17

**Try to define an object of type `Disc_quote` and see what errors you get from the compiler.**

Error: Allocating an object of abstract class type `Disc_quote`

## Exercise 15.18

**Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren’t allowed:**

```cpp
Base *p = &d1; // d1 has type Pub_Derv (Legal)

p = &d2; // d2 has type Priv_Derv (Illegal, User code may use the derived-to-base conversion only if inherits publicly)

p = &d3; // d3 has type Prot_Derv (Illegal, User code may use the derived-to-base conversion only if inherits publicly)

p = &dd1; // dd1 has type Derived_from_Public (Legal)

p = &dd2; // dd2 has type Derived_from_Private (Illegal, User code may use the derived-to-base conversion only if inherits publicly)

p = &dd3; // dd3 has type Derived_from_Protected(Illegal, User code may use the derived-to-base conversion only if inherits publicly)

```

## Exercise 15.19

**Assume that each of the classes from page 612 and page 613 has a member function of the form:**

```cpp
void memfcn(Base &b) { b = *this; }
```

**For each class, determine whether this function would be legal.**

Because member functions and friends of derived class can use the conversion to base class regardless of how derived class inherits from base class. The derived-to-base conversion to a direct base class **is always accessible** to members and friends of a derived class.

```cpp
Pub_Derv  d1; // legal
Priv_Derv d2; // legal
Prot_Derv d3; // legal
```

Because member functions and friends of classes derived from derived class may use the derived-to-base conversion if derived class inherits from base class using either **public** or **protected**. Such code may not use the conversion if derived class inherits **privately** from base class.

```cpp
Derived_from_Public     dd1; // legal
Derived_from_Private    dd2; // illegal
Derived_from_Protected  dd3; // legal
```

## Exercise 15.20

**Write code to test your answers to the previous two exercises.**

[15.20 Solution Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.20%20Solution.hpp)

[15.20 main](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.20%20main.cpp)

## Exercise 15.21

**Choose one of the following general abstractions containing a family of types (or choose one of your own). Organize the types into an inheritance hierarchy:**

(a) Graphical file formats (such as gif, tiff, jpeg, bmp)

(b) Geometric primitives (such as box, circle, sphere, cone)

(c) C+ + language types (such as class, function, member function)

I choose (b).

[15.21 GeometricPrimitives Header](https://github.com/Yunxiang-Li/Cpp_Primer/blob/master/Chapter%2015.%20Object-Oriented%20Programming/Codes/15.21%20GeometricPrimitives.hpp)

## Exercise 15.22

**For the class you chose in the previous exercise, identify some of the likely virtual functions as well as public and protected members.**

Same as exercise 15.21.
