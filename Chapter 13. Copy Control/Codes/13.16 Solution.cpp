#include <iostream>

static int uniqueNum{1};

class numbered {
 public:
  numbered() : mysn(uniqueNum++) {}
  numbered(const numbered& anotherNumbered) {
      this -> mysn = anotherNumbered.mysn + 1;
  }

  int mysn;
};

void f (const numbered& s) { std::cout << s.mysn << std::endl; }


int main() {

    numbered a, b = a, c = b;
    f(a); f(b); f(c);

    return 0;
}

/** Output:
 * 1
 * 2
 * 3
 */
