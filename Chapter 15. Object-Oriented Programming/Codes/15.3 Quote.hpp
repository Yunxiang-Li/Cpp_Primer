#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <iostream>
#include <string>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string& bookNo, double price) : mBookNo(bookNo), mPrice(price) {}

  std::string isbn() const;
  virtual double net_price(size_t n) const;

  virtual ~Quote() = default;

 private:
  std::string mBookNo;

 protected:
  double mPrice;
};

double printTotal(std::ostream os, const Quote& quote, size_t n) {
    double res = quote.net_price(n);
    os << "ISBN: " << quote.isbn() << " # sold: " << n << " total due: " << ret << '\n';

    return res;
}

#endif

