#ifndef BULK_QUOTE_HPP
#define BULK_QUOTE_HPP

#include "Disc_quote.hpp"

class Bulk_quote : public Disc_quote {
 public:
    using Disc_quote::Disc_quote;

  virtual double net_price(size_t n) const override;

 protected:
  size_t m_qty{0};
  double m_discount{0.0};
};

#endif
