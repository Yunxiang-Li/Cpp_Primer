#ifndef EQUALCHECK_HPP
#define EQUALCHECK_HPP

class EqualCheck {
 public:
  explicit EqualCheck(int value) : m_value(value) {};
  bool operator()(int value) const;

 private:
  int m_value;
};

#endif
