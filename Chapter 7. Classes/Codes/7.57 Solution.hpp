#ifndef EX7_57_HPP
#define EX7_57_HPP

class Account {
 public:
  static double rate() { return interestRate; }
  static void rate(double);
 private:
  static constexpr double interestRate{0.03};
  static constexpr int period = 30;// period is a constant expression
  double daily_tbl[period];
};

#endif
