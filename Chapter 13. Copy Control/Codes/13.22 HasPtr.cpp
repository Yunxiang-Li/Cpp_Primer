#include "HasPtr.hpp"

HasPtr& HasPtr::operator=(const HasPtr& hp)
{
    std::string* newStr = new std::string(*hp.ps);
    delete this -> ps;
    this -> ps = newStr;
    this -> i = hp.i;
    return *this;
}

HasPtr::~HasPtr() {
    delete this -> ps;
}
