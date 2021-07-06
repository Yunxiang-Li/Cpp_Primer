#include "Bulk_quote.hpp"

Bulk_quote::Bulk_quote() {
    std::cout << "Bulk_quote default constructor!" << '\n';
}

Bulk_quote::Bulk_quote(const std::string &bookNo, double price, size_t qty, double discount) :
    Disc_quote(bookNo, price, qty, discount) {
    std::cout << "Bulk_quote 4 arguments' constructor!" << '\n';
}

Bulk_quote::Bulk_quote(const Bulk_quote& bulk_quote) : Disc_quote(bulk_quote) {
    std::cout << "Bulk_quote copy constructor!" << '\n';
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote&  bulk_quote) {
    std::cout << "Bulk_quote Copy assignment operator!" << '\n';
    Disc_quote::operator=(bulk_quote);
    return *this;
}

Bulk_quote::Bulk_quote(Bulk_quote&& bulk_quote) noexcept : Disc_quote(bulk_quote) {
    std::cout << "Bulk_quote move constructor!" << '\n';
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote&& bulk_quote) {
    std::cout << "Bulk_quote Move assignment operator!" << '\n';
    Disc_quote::operator=(bulk_quote);
    return *this;
}

double Bulk_quote::net_price(size_t n) const {
    if (n >= m_qty)
        return (1 - m_discount) * n * mPrice;
    return n * mPrice;
}
