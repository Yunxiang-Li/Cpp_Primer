#include "Disc_quote.hpp"

void Disc_quote::debug() const {
    Quote::debug();
    std::cout << "\tmin quantity: " << m_qty << "\tdiscount: " << m_discount << '\n';
}
