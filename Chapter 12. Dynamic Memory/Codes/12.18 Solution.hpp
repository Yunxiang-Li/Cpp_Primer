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
  StrBlob(std::initializer_list<std::string> initializer_list);

  typedef std::vector<std::string>::size_type dataSize;
  friend class StrBlobPtr;
  StrBlobPtr begin();
  StrBlobPtr end();

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
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.m_data), curr(sz) {}
  bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
  std::string& deref() const
  {
      auto p = check(curr, "dereference past end");
      return (*p)[curr];
  }
  StrBlobPtr& incr()
  {
      check(curr, "increment past end of StrBlobPtr");
      ++curr;
      return *this;
  }

 private:
  std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string& msg) const
  {
      auto ret = wptr.lock();
      if (!ret) throw std::runtime_error("unbound StrBlobPtr");
      if (i >= ret->size()) throw std::out_of_range(msg);
      return ret;
  }
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
};

#endif
