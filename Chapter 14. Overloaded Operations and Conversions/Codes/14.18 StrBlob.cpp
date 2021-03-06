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

void StrBlob::push_back(const std::string &&str) {
    m_data ->emplace_back(std::move(str));
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

StrBlob& StrBlob::operator=(const StrBlob& sb)
{
    this -> m_data = std::make_shared<std::vector<std::string>>(*(sb.m_data));
    return *this;
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs) {
    return *(lhs.m_data) == *(rhs.m_data);
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs) {
    return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

bool operator>(const StrBlob& lhs, const StrBlob& rhs) {
    return (rhs < lhs);
}

bool operator<=(const StrBlob& lhs, const StrBlob& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const StrBlob& lhs, const StrBlob& rhs) {
    return !(lhs < rhs);
}


const ConstStrBlobPtr StrBlob::begin() const{
    return ConstStrBlobPtr(*this);
}

const ConstStrBlobPtr StrBlob::end() const{
    return ConstStrBlobPtr(*this, m_data -> size());
}

const std::string & ConstStrBlobPtr::deref() const {
    std::shared_ptr<std::vector<std::string>> p = ConstStrBlobPtr::check(m_curr, "dereference past end");
    return (*p)[m_curr];
}

ConstStrBlobPtr & ConstStrBlobPtr::incr() {
    ConstStrBlobPtr::check(m_curr, "increment past end of StrBlobPtr");
    ++m_curr;
    return *this;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(size_t i, const std::string &msg) const {
    auto ret = m_wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return (lhs.m_curr == rhs.m_curr);
}

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return (lhs.m_curr < rhs.m_curr);
}

bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return (rhs < lhs);
}

bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return !(lhs < rhs);
}
