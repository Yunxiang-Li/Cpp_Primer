#include "Book.hpp"
#include <iostream>

std::istream& operator>>(std::istream& in, Book& book)
{
    in >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_;
    if (!in) book = Book();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Book& book)
{
    out << book.no_ << " " << book.name_ << " " << book.author_ << " "
        << book.pubdate_;
    return out;
}

bool operator==(const Book& lhs, const Book& rhs)
{
    return lhs.no_ == rhs.no_;
}

bool operator!=(const Book& lhs, const Book& rhs)
{
    return !(lhs == rhs);
}

Book& Book::operator+=(const Book& book) {
    if (book == *this)
        this -> no_ += book.no_;
    return *this;
}

Book operator+(const Book& bookOne, const Book& bookTwo) {
    Book res = bookOne;
    res += bookTwo;
    return res;
}

bool operator<(const Book& bookOne, const Book& bookTwo) {
    return (bookOne.no_ < bookTwo.no_);
}

bool operator>(const Book& bookOne, const Book& bookTwo) {
    return (bookTwo < bookOne);
}
