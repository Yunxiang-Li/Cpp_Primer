#include "HasPtr.hpp"

HasPtr& HasPtr::operator=(const HasPtr& hp)
{
    if (this != &hp) {
        ++(*hp.m_countPtr);

        if (--m_countPtr == nullptr) {
            delete this -> ps;
            delete m_countPtr;
        }

        this -> ps = hp.ps;
        this -> i = hp.i;
        m_countPtr = hp.m_countPtr;
    }

    return *this;
}

HasPtr::HasPtr(HasPtr&& rhs) noexcept : ps(rhs.ps), i(rhs.i), m_countPtr(rhs.m_countPtr) {
    rhs.ps = nullptr;
    rhs.m_countPtr = nullptr;
}

HasPtr & HasPtr::operator=(HasPtr&& rhs) noexcept {
    if (this != &rhs) {
        ++(*rhs.m_countPtr);
        if (--m_countPtr == nullptr) {
            delete this -> ps;
            delete m_countPtr;
        }

        this -> ps = rhs.ps;
        this -> i = rhs.i;
        m_countPtr = rhs.m_countPtr;

        rhs.ps = nullptr;
        rhs.m_countPtr = nullptr;
    }

    return *this;
}

HasPtr::~HasPtr() {

    if (--m_countPtr == nullptr) {
        delete this -> ps;
        delete m_countPtr;
    }
}

std::string * HasPtr::getPs() {
    return this -> ps;
}
