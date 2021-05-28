#include "Foo.hpp"

int main() {

    // call && version
    Foo().sorted();
    Foo f;
    // call const & version which will call && version inside.
    f.sorted();

    return 0;
}
