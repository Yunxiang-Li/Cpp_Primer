#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#pragma once

#include <string>

class Employee {
 public:

  Employee();
  explicit Employee(const std::string& str);

  static int increment;
  std::string mName;
  int mIdentifier;

};

#endif
