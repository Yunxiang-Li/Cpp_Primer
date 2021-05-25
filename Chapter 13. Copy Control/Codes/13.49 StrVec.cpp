#include "StrVec.hpp"
#include <memory>
#include <algorithm>

std::allocator<std::string>StrVec::alloc;

StrVec::StrVec(std::initializer_list<std::string> strList) {
    std::pair<std::string*, std::string*> newPair = m_alloc_n_copy(strList.begin(), strList.end());
    m_elements = newPair.first;
    m_first_free = newPair.second;
    m_cap = newPair.second;
}

StrVec::StrVec(const StrVec& str_vec) {
    std::pair<std::string*, std::string*> newPair = m_alloc_n_copy(str_vec.m_begin(), str_vec.m_end());
    m_elements = newPair.first;
    m_first_free = newPair.second;
    m_cap = newPair.second;
}

StrVec& StrVec::operator=(const StrVec& str_vec) {
    std::pair<std::string*, std::string*> newPair = m_alloc_n_copy(str_vec.m_begin(), str_vec.m_end());
    m_free();
    m_elements = newPair.first;
    m_first_free = newPair.second;
    m_cap = newPair.second;
    return *this;
}

StrVec::StrVec(StrVec&& str_vec) noexcept : m_elements(str_vec.m_elements), m_first_free(str_vec.m_first_free),
m_cap(str_vec.m_cap) {
    str_vec.m_elements = str_vec.m_first_free = str_vec.m_cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& str_vec) noexcept {
    if (this != &str_vec) {
        m_free();
        m_elements = str_vec.m_elements;
        m_first_free = str_vec.m_first_free;
        m_cap = str_vec.m_cap;
        str_vec.m_elements = str_vec.m_first_free = str_vec.m_cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() {
    m_free();
}

void StrVec::m_push_back(const std::string& str) {
    m_chk_n_alloc();
    alloc.construct(m_first_free++, str);
}

size_t StrVec::m_size() const {
    return m_first_free - m_elements;
}

size_t StrVec::m_capacity() const {
    return m_cap - m_first_free;
}

std::string * StrVec::m_begin() const {
    return m_elements;
}

std::string * StrVec::m_end() const {
    return m_first_free;
}

void StrVec::m_reserve(size_t newCap) {
    if (newCap < m_capacity())
        return;
    m_alloc_n_move(newCap);
}

void StrVec::m_resize(size_t newSize) {
    m_resize(newSize, std::string());
}

void StrVec::m_resize(size_t newSize, const std::string& str) {
    if (newSize > m_size()) {
        if (newSize > m_capacity())
            m_reserve(newSize * 2);
        for (size_t i = 0; i != newSize; ++i)
            alloc.construct(m_first_free++, str);
    }
}

std::pair<std::string *, std::string *> StrVec::m_alloc_n_copy(const std::string* strOne, const std::string* strTwo) {
    std::string* beginPtr = alloc.allocate(strTwo - strOne, 0);

    return {beginPtr, std::uninitialized_copy(strOne, strTwo, beginPtr)};
}

void StrVec::m_free() {
    if (m_elements)
        std::for_each(m_elements, m_first_free, [](std::string& eachStr){alloc.destroy(&eachStr);});
    alloc.deallocate(m_elements, m_capacity());
}

void StrVec::m_chk_n_alloc() {
    if (m_size() == m_capacity())
        m_reallocate();
}

void StrVec::m_reallocate() {
    size_t newCap = m_size() ? m_size() * 2 : 1;
    m_alloc_n_move(newCap);
}

void StrVec::m_alloc_n_move(size_t newCap) {
    std::string* ptr = alloc.allocate(newCap);
    std::string* newPtr = ptr;
    std::string* currPtr = m_elements;

    for (size_t i = 0; i != m_size(); ++i)
        alloc.construct(newPtr++, std::move(*(currPtr++)));

    m_free();

    m_elements = ptr;
    m_first_free = newPtr;
    m_cap = m_elements + newCap;
}
