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
