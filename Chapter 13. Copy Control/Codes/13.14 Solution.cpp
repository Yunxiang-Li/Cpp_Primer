#include <iostream>

static int uniqueNum{10};

class numbered {
 public:
  numbered() : mysn(uniqueNum++) {}

  int mysn;
};

void f (numbered s) { std::cout << s.mysn << std::endl; }


int main() {

    numbered a, b = a, c = b;
    f(a); f(b); f(c);

    return 0;
}

