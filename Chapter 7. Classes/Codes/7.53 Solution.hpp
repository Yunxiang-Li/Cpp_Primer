#ifndef EX7_53_HPP
#define EX7_53_HPP

class Debug {

 public:
  constexpr Debug(bool hasError = false) : m_hwError(hasError) , m_IOError(hasError),
                                           m_otherError(hasError) {}
  constexpr Debug(bool hw, bool IO, bool other) : m_hwError(hw) , m_IOError(IO),
                                           m_otherError(other) {}

  constexpr bool hasError() {
    return (m_IOError || m_hwError || m_otherError);
  }

  void set_hw(bool hw) {
    m_hwError = hw;
  }

  void set_io(bool IO) {
    m_IOError = IO;
  }

  void set_other(bool other) {
    m_otherError = other;
  }

 private:
  bool m_hwError;
  bool m_IOError;
  bool m_otherError;
};

#endif
