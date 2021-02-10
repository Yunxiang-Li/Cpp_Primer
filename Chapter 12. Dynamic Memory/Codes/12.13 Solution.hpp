#ifndef STRBLOB_HPP
#define STRBLOB_HPP

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

#include "StrBlobPtr.hpp"

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

#endif
