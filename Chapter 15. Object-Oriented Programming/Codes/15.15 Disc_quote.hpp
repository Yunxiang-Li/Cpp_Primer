#ifndef DISC_QUOTE_HPP
#define DISC_QUOTE_HPP

#include "Quote.hpp"

class Disc_quote : public Quote {
 public:
  Disc_quote() = default;
  Disc_quote(const std::string& bookNo, double price, size_t qty, double discount) : Quote(bookNo, price), m_qty(qty),
  m_discount(discount) {}

  virtual double net_price(size_t n) const override = 0;

 protected:
  size_t m_qty{0};
  double m_discount{0.0};
};

#endif
