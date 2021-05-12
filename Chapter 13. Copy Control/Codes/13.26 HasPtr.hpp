#ifndef HASPTR_HPP
#define HASPTR_HPP

#include <string>

class HasPtr
{
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), m_countPtr(new std::size_t(1)) { }

  HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i), m_countPtr(hp.m_countPtr) { ++(*m_countPtr);}

  HasPtr& operator=(const HasPtr& hp);

  ~HasPtr();

 private:
  std::string *ps;
  int    i;
  std::size_t* m_countPtr;

};

#endif
