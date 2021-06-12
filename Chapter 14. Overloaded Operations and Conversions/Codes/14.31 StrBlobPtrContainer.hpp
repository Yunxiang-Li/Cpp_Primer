#ifndef STRBLOBPTRCONTAINER_HPP
#define STRBLOBPTRCONTAINER_HPP

class ConstStrBlobPtr;

class StrBlobPtrContainer {
 public:
  StrBlobPtrContainer() = default;
  explicit StrBlobPtrContainer(ConstStrBlobPtr* ptr) : m_ptr(ptr) {};

  ConstStrBlobPtr& operator*();
  ConstStrBlobPtr* operator->();

 private:
  ConstStrBlobPtr* m_ptr{nullptr};
};

#endif
