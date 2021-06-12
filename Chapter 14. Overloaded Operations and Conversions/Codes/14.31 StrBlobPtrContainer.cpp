#include "StrBlobPtrContainer.hpp"
#include "StrBlob.hpp"

ConstStrBlobPtr& StrBlobPtrContainer::operator*()
{
    return *(this->m_ptr);
}

ConstStrBlobPtr* StrBlobPtrContainer::operator->()
{
    return &this->operator*();
}
