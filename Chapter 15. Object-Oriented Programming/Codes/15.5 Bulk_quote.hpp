#ifndef BULK_QUOTE_HPP
#define BULK_QUOTE_HPP

#include "Quote.hpp"

class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string& bookNo, double price, size_t qty, double discount) : Quote(bookNo, price), m_qty(qty),
  m_discount(discount) {}

  virtual double net_price(size_t n) const override;

 protected:
  size_t m_qty{0};
  double m_discount{0.0};
};

#endif
