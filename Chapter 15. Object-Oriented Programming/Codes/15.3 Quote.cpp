#include "Quote.hpp"

std::string Quote::isbn() const {
    return mBookNo;
}

double Quote::net_price(size_t n) const {
    return  mPrice * n;
}
