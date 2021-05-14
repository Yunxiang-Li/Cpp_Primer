#ifndef HASPTR_HPP
#define HASPTR_HPP

#include <string>
#include <iostream>

class HasPtr
{
  friend void swap(HasPtr&, HasPtr&);
  friend bool operator< (const HasPtr&, const HasPtr&);

 public:
  explicit HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), m_countPtr(new std::size_t(1)) { }

  HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i), m_countPtr(hp.m_countPtr) { ++(*m_countPtr);}

  HasPtr& operator=(const HasPtr& hp);

  ~HasPtr();

  std::string* getPs();

 private:
  std::string *ps;
  int    i;
  std::size_t* m_countPtr;

};

inline void swap(HasPtr& HasPtrOne, HasPtr& HasPtrTwo) {
    std::swap(HasPtrOne.i, HasPtrTwo.i);
    std::swap(HasPtrOne.ps, HasPtrTwo.ps);
    std::swap(HasPtrOne.m_countPtr, HasPtrTwo.m_countPtr);

    std::cout << "swap finished!" << '\n';
}

inline bool operator<(const HasPtr& HasPtrOne, const HasPtr& HasPtrTwo) {
    return (*(HasPtrOne.ps) < *(HasPtrTwo.ps));
}

#endif
