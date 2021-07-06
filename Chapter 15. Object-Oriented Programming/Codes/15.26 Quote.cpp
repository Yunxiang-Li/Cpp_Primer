#include "Quote.hpp"

Quote::Quote() {
    std::cout << "Quote default constructor!" << '\n';
}

Quote::Quote(const Quote& quote) {
    std::cout << "Quote copy constructor!" << '\n';
}

Quote& Quote::operator=(const Quote& quote) {
    std::cout << "Quote copy assignment operator!" << '\n';
    mBookNo = quote.mBookNo;
    mPrice = quote.mPrice;
    return *this;
}

Quote::Quote(Quote&& quote) noexcept : mBookNo(std::move(quote.mBookNo)), mPrice(quote.mPrice){
    std::cout << "Quote move constructor!" << '\n';
}

Quote& Quote::operator=(Quote&& quote) noexcept {
    std::cout << "Quote copy assignment operator!" << '\n';
    mBookNo = std::move(quote.mBookNo);
    mPrice = quote.mPrice;
    return *this;
}

Quote::~Quote() {
    std::cout << "Quote destructor!" << '\n';
}

std::string Quote::isbn() const {
    return mBookNo;
}

double Quote::net_price(size_t n) const {
    return  mPrice * n;
}

void Quote::debug() const {
    std::cout << "data members: \n" << "\tbookNo: " << mBookNo << "\tprice: " << mPrice << '\n';
}
