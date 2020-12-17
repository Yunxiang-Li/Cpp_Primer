#ifndef EX7_31_HPP
#define EX7_31_HPP

class Y;

class X {
  Y* m_yPtr{nullptr};
};

class Y {
  X m_X;
};

#endif
