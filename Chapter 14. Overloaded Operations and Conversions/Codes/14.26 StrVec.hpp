#ifndef STRVEC_HPP
#define STRVEC_HPP

#include <string>
#include <initializer_list>

class StrVec {

  friend bool operator==(const StrVec&, const StrVec&);
  friend bool operator!=(const StrVec&, const StrVec&);

  friend bool operator<(const StrVec&, const StrVec&);
  friend bool operator>(const StrVec&, const StrVec&);
  friend bool operator<=(const StrVec&, const StrVec&);
  friend bool operator>=(const StrVec&, const StrVec&);

 public:
  StrVec() : m_elements(nullptr), m_first_free(nullptr), m_cap(nullptr) {}
  explicit StrVec(std::initializer_list<std::string>);
  StrVec(const StrVec&);
  StrVec& operator=(const StrVec&);
  StrVec(StrVec&&) noexcept;
  StrVec& operator=(StrVec&&) noexcept;
  std::string& operator[](size_t n);
  const std::string& operator[](size_t n) const;
  ~StrVec();

  StrVec& operator=(std::initializer_list<std::string>);

  void m_push_back(const std::string&);
  size_t m_size() const;
  size_t m_capacity() const;
  std::string* m_begin() const;
  std::string* m_end() const;

  void m_reserve(size_t newCap);
  void m_resize(size_t newSize);
  void m_resize(size_t newSize, const std::string&);


 private:
    std::pair<std::string*, std::string*> m_alloc_n_copy(const std::string*, const std::string*);
    void m_free();
    void m_chk_n_alloc();
    void m_reallocate();
    void m_alloc_n_move(size_t newCap);

    std::string* m_elements;
    std::string* m_first_free;
    std::string* m_cap;
    static std::allocator<std::string> alloc;
};

#endif
