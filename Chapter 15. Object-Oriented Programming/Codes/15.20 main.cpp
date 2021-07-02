#include "Solution.hpp"

int main() {
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;

    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1;  // d1 has type Pub_Derv     --  legal
    p = &d2;        // d2 has type Priv_Derv    --  illegal
    p = &d3;        // d3 has type Prot_Derv    --  illegal

    p = &dd1;       // dd1 has type Derived_from_Public     --  legal
    p = &dd2;       // dd2 has type Derived_from_Private    --  illegal
    p = &dd3;       // dd3 has type Derived_from_Protected  --  illegal

    return 0;
};
