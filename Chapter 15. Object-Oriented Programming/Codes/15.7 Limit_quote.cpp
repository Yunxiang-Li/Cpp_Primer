#include "Limit_quote.hpp"

double Limit_quote::net_price(size_t n) const {
    if (n <= m_max)
        return (1 - m_discount) * n * mPrice;
    return n * mPrice;
}
