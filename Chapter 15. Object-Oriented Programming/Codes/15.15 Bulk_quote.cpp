#include "Bulk_quote.hpp"

double Bulk_quote::net_price(size_t n) const {
    if (n >= m_qty)
        return (1 - m_discount) * n * mPrice;
    return n * mPrice;
}
