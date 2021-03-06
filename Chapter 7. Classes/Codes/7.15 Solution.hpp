#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>

class Person {
 private:
  std::string m_name;
  std::string m_address;

 public:
  Person() = default;
  Person(const std::string& name, const std::string& address)
      : m_name(name), m_address(address)
  {
  }
 
  const std::string& getName() const;
  const std::string& getAddress() const;

  std::istream& read(std::istream& is, Person& person)
  {
    is >> person.m_name >> person.m_address;
    if (!is)
      person = Person();
    return is;
  }

  std::ostream& print(std::ostream& os, const Person& person)
  {
    os << person.m_name << " " << person.m_address;
    return os;
  }
};

#endif
