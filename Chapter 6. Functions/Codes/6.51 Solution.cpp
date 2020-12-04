#include <iostream>

void f()
{
  std::cout << "f() is called" << std::endl;
}

void f(int)
{
  std::cout << "f(int) is called" << std::endl;
}

void f(int, int)
{
  std::cout << "f(int, int) is called" << std::endl;
}

void f(double, double = 3.0)
{
  std::cout << "f(double, double) is called" << std::endl;
}

int main()
{
  // f(2.56, 42); //this 'f' is ambiguous.
  f();
  f(42);
  f(42, 0);
  f(2.56, 3.14);
  f(1.2);
}
