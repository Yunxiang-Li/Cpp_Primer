#ifndef LIMIT_QUOTE_HPP
#define LIMIT_QUOTE_HPP

#include "Disc_quote.hpp"

class Limit_quote : public Disc_quote {
 public:
  Limit_quote() = default;
  Limit_quote(const std::string& bookNo, double price, size_t qty, double discount, size_t max) :
      Disc_quote(bookNo, price, qty, discount), m_max(max) {}

  virtual double net_price(size_t n) const override;
  virtual void debug() const override;

 protected:
  size_t m_discount;
  size_t m_max;
};

#endif
