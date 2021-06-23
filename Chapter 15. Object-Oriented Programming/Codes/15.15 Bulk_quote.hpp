#ifndef BULK_QUOTE_HPP
#define BULK_QUOTE_HPP

#include "Disc_quote.hpp"

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string& bookNo, double price, size_t qty, double discount) :
      Disc_quote(bookNo, price, qty, discount) {}

  virtual double net_price(size_t n) const override;

 protected:
  size_t m_qty{0};
  double m_discount{0.0};
};

#endif
