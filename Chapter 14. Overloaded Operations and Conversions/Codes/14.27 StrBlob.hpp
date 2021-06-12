#ifndef STRBLOB_HPP
#define STRBLOB_HPP

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <string>

class ConstStrBlobPtr;

class StrBlob {

  friend bool operator==(const StrBlob&, const StrBlob&);
  friend bool operator!=(const StrBlob&, const StrBlob&);

  friend bool operator<(const StrBlob&, const StrBlob&);
  friend bool operator>(const StrBlob&, const StrBlob&);
  friend bool operator<=(const StrBlob&, const StrBlob&);
  friend bool operator>=(const StrBlob&, const StrBlob&);

 public:
  StrBlob();
  explicit StrBlob(std::initializer_list<std::string> initializer_list);

  typedef std::vector<std::string>::size_type dataSize;

  // copy constructor
  StrBlob(const StrBlob& sb)
      : m_data(std::make_shared<std::vector<std::string>>(*(sb.m_data))){}

  // copy assignment operators
  StrBlob& operator=(const StrBlob& sb);

  std::string& operator[](size_t n);
  const std::string& operator[](size_t n) const;

  friend class ConstStrBlobPtr;
  const ConstStrBlobPtr begin() const;
  const ConstStrBlobPtr end() const;

  dataSize size() const;
  bool empty() const;
  void push_back(const std::string& str);
  void pop_back();
  std::string& front();
  const std::string& front() const;
  std::string& back();
  const std::string& back() const;

  void push_back(const std::string&& str);

 private:
  std::shared_ptr<std::vector<std::string>> m_data;
  void check(dataSize i, const std::string& msg) const;

};

class ConstStrBlobPtr {

  friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
  friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

  friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
  friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
  friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
  friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

 public:
  ConstStrBlobPtr() : m_curr(0) {}
  explicit ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : m_wptr(a.m_data), m_curr(sz) {}
  bool operator!=(const ConstStrBlobPtr& p) { return p.m_curr != m_curr; }

  const std::string& operator[](size_t n) const;

  ConstStrBlobPtr& operator++();
  ConstStrBlobPtr operator++(int);

  ConstStrBlobPtr& operator--();
  ConstStrBlobPtr operator--(int);

  const std::string& deref() const;
  ConstStrBlobPtr& incr();

 private:
  std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string& msg) const;
  std::weak_ptr<std::vector<std::string>> m_wptr;
  size_t m_curr;
};

#endif
