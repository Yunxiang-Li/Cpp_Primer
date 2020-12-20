#ifndef EX7_43_HPP
#define EX7_43_HPP

class NoDefault {
 public:
  NoDefault(int) {};
};

class C {
 public:
  C() : m_member(0) {

  }

 private:
  NoDefault m_member;

};

#endif
