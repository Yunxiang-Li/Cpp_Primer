#include <string>

#ifndef PERSON_HPP
#define PERSON_HPP

class Person {
 private:
  std::string m_name;
  std::string m_address;

 public:
  const std::string& getName() const;
  const std::string& getAddress() const;
};

#endif
