#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <iostream>
#include <string>

class Quote {
 public:
  Quote();

  Quote(const std::string& bookNo, double price) : mBookNo(bookNo), mPrice(price) {
      std::cout << "Quote 2 arguments' constructor!" << '\n';
  }

  Quote(const Quote&);

  Quote& operator=(const Quote&);

  Quote(Quote&&) noexcept;

  Quote& operator=(Quote&&) noexcept;

  std::string isbn() const;
  virtual double net_price(size_t n) const;
  virtual void debug() const;

  virtual ~Quote();

 private:
  std::string mBookNo;

 protected:
  double mPrice;
};

static double printTotal(std::ostream& os, const Quote& quote, size_t n) {
    double res = quote.net_price(n);
    os << "ISBN: " << quote.isbn() << " # sold: " << n << " total due: " << res << '\n';

    return res;
}

#endif
