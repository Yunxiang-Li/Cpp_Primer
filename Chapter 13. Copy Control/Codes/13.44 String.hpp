#ifndef STRING_HPP
#define STRING_HPP

#include <cstdlib>
#include <utility>
#include <memory>

class String {
 public:
    String() : String("") {}
    explicit String(const char*);
    String(const String&);
    String& operator=(const String&);
    ~String();
 
    const char* m_c_str() const;
    size_t m_size() const;
    size_t m_length() const;

 private:
    std::pair<char*, char*> m_alloc_n_copy(const char*, const char*);
    void m_range_initialize(const char*, const char*);
    void m_free();

    char* m_elements;
    char* m_first_free;

    static std::allocator<char> alloc;
};

#endif
