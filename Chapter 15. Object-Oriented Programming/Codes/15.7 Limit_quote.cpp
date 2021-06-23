#include "Limit_quote.hpp"

double Limit_quote::net_price(size_t n) const {
    if (n <= m_max)
        return (1 - m_discount) * n * mPrice;
    return (n - m_max) * mPrice + m_max * mPrice * (1 - m_discount);
}

void Limit_quote::debug() const {
    Quote::debug();
    std::cout << "\tmax limit: " << m_max << "\tdiscount: " << m_discount << '\n';
}
