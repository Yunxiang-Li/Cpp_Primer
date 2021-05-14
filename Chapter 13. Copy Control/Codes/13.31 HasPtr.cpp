#include "HasPtr.hpp"

HasPtr& HasPtr::operator=(const HasPtr& hp)
{
    ++(*hp.m_countPtr);

    if (--m_countPtr == 0) {
        delete this -> ps;
        delete m_countPtr;
    }

    this -> ps = hp.ps;
    this -> i = hp.i;
    m_countPtr = hp.m_countPtr;

    return *this;
}

HasPtr::~HasPtr() {

    if (--m_countPtr == 0) {
        delete this -> ps;
        delete m_countPtr;
    }
}

std::string * HasPtr::getPs() {
    return this -> ps;
}
