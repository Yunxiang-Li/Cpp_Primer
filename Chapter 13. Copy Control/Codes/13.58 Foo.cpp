#include "Foo.hpp"
#include <algorithm>
#include <iostream>

Foo Foo::sorted() const &{
/*    // Version provided
    Foo ret(*this);
    std::sort(ret.data.begin(), ret.data.end());
    return ret;*/

    std::cout << "const & sorted function" << std::endl;

/*    // Exercise 13.56
    Foo ret(*this);
    ret.sorted();
    return ret;*/

    // Exercise 13.57 Version
    return Foo(*this).sorted();
}

Foo Foo::sorted() &&{
    std::cout << "&& sorted function" << std::endl;
    std::sort(this -> data.begin(), this -> data.end());
    return *this;
}
