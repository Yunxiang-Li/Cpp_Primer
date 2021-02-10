#ifndef STRBLOB_HPP
#define STRBLOB_HPP

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

class StrBlobPtr;

class StrBlob {
 public:
  StrBlob();
  explicit StrBlob(std::initializer_list<std::string> initializer_list);

  typedef std::vector<std::string>::size_type dataSize;
  friend class StrBlobPtr;
  const StrBlobPtr begin() const;
  const StrBlobPtr end() const;

  dataSize size() const;
  bool empty() const;
  void push_back(const std::string& str);
  void pop_back();
  std::string& front();
  const std::string& front() const;
  std::string& back();
  const std::string& back() const;

 private:
  std::shared_ptr<std::vector<std::string>> m_data;
  void check(dataSize i, const std::string& msg) const;

};

class StrBlobPtr {
 public:
  StrBlobPtr() : m_curr(0) {}
  explicit StrBlobPtr(const StrBlob& a, size_t sz = 0) : m_wptr(a.m_data), m_curr(sz) {}
  bool operator!=(const StrBlobPtr& p) { return p.m_curr != m_curr; }
  std::string& deref() const;
  StrBlobPtr& incr();

 private:
  std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string& msg) const;
  std::weak_ptr<std::vector<std::string>> m_wptr;
  size_t m_curr;
};

#endif
