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

char& String::operator[](size_t n) {
    return m_elements[n];
}

const char& String::operator[](size_t n) const {
    return m_elements[n];
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

std::ostream& operator<<(std::ostream& os, const String& Str) {
    const char* ptr = Str.m_c_str();

    while (*ptr)
        os << *(ptr++);

    return os;
}

char * String::m_begin() const {
    return m_elements;
}

char * String::m_end() const {
    return m_first_free;
}

bool operator==(const String& lhs, const String& rhs) {
    return (lhs.m_size() == rhs.m_size() && std::equal(lhs.m_begin(), lhs.m_end(), rhs.m_begin()));
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs) {
    return std::lexicographical_compare(lhs.m_begin(), lhs.m_end(), rhs.m_begin(), rhs.m_end());
}

bool operator>(const String& lhs, const String& rhs) {
    return (rhs < lhs);
}

bool operator<=(const String& lhs, const String& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const String& lhs, const String& rhs) {
    return !(lhs < rhs);
}

std::allocator<char> String::alloc;
