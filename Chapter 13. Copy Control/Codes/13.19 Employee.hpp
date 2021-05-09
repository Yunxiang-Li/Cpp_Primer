#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#pragma once

#include <string>

class Employee {
 public:

  Employee();
  explicit Employee(const std::string& str);
  ~Employee() = default;
  
  Employee(const Employee&) = delete;
  Employee& operator=(const Employee&) = delete;

  static int increment;
  std::string mName;
  int mIdentifier;

};

#endif
