class NoDefault {
 public:
  NoDefault(int) {};
};

class C {
 public:
  () : m_member(NoDefault(0)) {} {

  }

 private:
  NoDefault m_member;

};
