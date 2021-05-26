#include <algorithm>
#include <iostream>
#include "String.hpp"

String::String(const char* charPtr) {
    char* destCharPtr = const_cast<char*>(charPtr);
    while (*destCharPtr) ++destCharPtr;

    m_range_initialize(charPtr, destCharPtr);
}

String::String(const String& str) {
    m_range_initialize(str.m_elements, str.m_first_free);
}

String& String::operator=(const String& str) {
    std::pair<char*, char*> pair = m_alloc_n_copy(str.m_elements, str.m_first_free);
    m_free();
    m_elements = pair.first;
    m_first_free = pair.second;
    return *this;
}

String::String(String&& str) noexcept : m_elements(str.m_elements), m_first_free(str.m_first_free)
{
    str.m_elements = str.m_first_free = nullptr;
    std::cout << "Move constructor here!";
}

String & String::operator=(String&& str) noexcept {
    std::cout << "Move assignment here!";
    if (this != &str) {
        m_free();
        m_elements = str.m_elements;
        m_first_free = str.m_first_free;
        str.m_elements = str.m_first_free = nullptr;
    }
    return *this;
}

String::~String() {
    m_free();
}

const char* String::m_c_str() const {
    return m_elements;
}

size_t String::m_size() const {
    return (m_first_free - m_elements);
}

size_t String::m_length() const {
    return m_size();
}

std::pair<char *, char *> String::m_alloc_n_copy(const char* begin, const char* end) {
    char* beginPtr = alloc.allocate(end - begin, nullptr);
    return {beginPtr, std::uninitialized_copy(begin, end, beginPtr)};
}

void String::m_range_initialize(const char* begin, const char* end) {
    std::pair<char*, char*> pair = m_alloc_n_copy(begin, end);
    m_elements = pair.first;
    m_first_free = pair.second;
}

void String::m_free() {
    if (m_elements)
        std::for_each(m_elements, m_first_free, [](char& charPtr){alloc.destroy(&charPtr);});
}

std::allocator<char> String::alloc;
