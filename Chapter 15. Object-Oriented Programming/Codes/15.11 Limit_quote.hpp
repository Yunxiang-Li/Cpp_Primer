#ifndef LIMIT_QUOTE_HPP
#define LIMIT_QUOTE_HPP

#include "Quote.hpp"

class Limit_quote : public Quote {
 public:
  Limit_quote() = default;
  Limit_quote(const std::string& bookNo, double price, size_t max, double discount) :
      Quote(bookNo, price), m_max(max), m_discount(discount) {}

  virtual double net_price(size_t n) const override;
  virtual void debug() const override;

 protected:
  size_t m_max;
  size_t m_discount;
};

#endif
