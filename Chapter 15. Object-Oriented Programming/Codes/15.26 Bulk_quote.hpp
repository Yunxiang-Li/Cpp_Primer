#ifndef BULK_QUOTE_HPP
#define BULK_QUOTE_HPP

#include "Disc_quote.hpp"

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote();
  Bulk_quote(const std::string& bookNo, double price, size_t qty, double discount);
  Bulk_quote(const Bulk_quote&);
  Bulk_quote& operator=(const Bulk_quote&);
  Bulk_quote(Bulk_quote&&) noexcept;
  Bulk_quote& operator=(Bulk_quote&&);

  virtual double net_price(size_t n) const override;

 protected:
  size_t m_qty{0};
  double m_discount{0.0};
};

#endif
