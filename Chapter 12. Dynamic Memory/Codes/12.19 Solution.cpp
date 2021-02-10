#include <exception>
#include "StrBlob.hpp"

StrBlob::StrBlob() : m_data(std::make_shared<std::vector<std::string>>()){};

StrBlob::StrBlob(std::initializer_list<std::string> initializer_list) :
    m_data(std::make_shared<std::vector<std::string>>(initializer_list)){};

StrBlob::dataSize StrBlob::size() const {
    return m_data -> size();
}

bool StrBlob::empty() const {
    return m_data -> empty();
}

void StrBlob::push_back(const std::string &str) {
    m_data -> emplace_back(str);
}

void StrBlob::pop_back() {
    check(0, "Call pop_back on an empty StrBlob object!");
    m_data -> pop_back();
}

std::string& StrBlob::front() {
    check(0, "Call front on an empty StrBlob object!");
    return m_data -> front();
}

const std::string& StrBlob::front() const {
    check(0, "Call front on an empty StrBlob object!");
    return m_data -> front();
}

std::string& StrBlob::back() {
    check(0, "Call back on an empty StrBlob object!");
    return m_data -> back();
}

const std::string& StrBlob::back() const {
    check(0, "Call back on an empty StrBlob object!");
    return m_data -> back();
}

void StrBlob::check(dataSize i, const std::string &msg) const {
    if (i >= m_data -> size())
        throw std::out_of_range(msg);
}

const StrBlobPtr StrBlob::begin() const{
    return StrBlobPtr(*this);
}

const StrBlobPtr StrBlob::end() const{
    return StrBlobPtr(*this, m_data -> size());
}

std::string & StrBlobPtr::deref() const {
    std::shared_ptr<std::vector<std::string>> p = StrBlobPtr::check(m_curr, "dereference past end");
    return (*p)[m_curr];
}

StrBlobPtr & StrBlobPtr::incr() {
    StrBlobPtr::check(m_curr, "increment past end of StrBlobPtr");
    ++m_curr;
    return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string &msg) const {
    auto ret = m_wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}
