#include "Employee.hpp"

int Employee::increment{0};

Employee::Employee() : mIdentifier(increment++) {}

Employee::Employee(const std::string &str) : mName(str), mIdentifier(increment++) {}
