#include <algorithm>
#include <numeric>
#include <vector>

#include "7.26 Solution.hpp"

bool compareIsbn(const Sales_data& sd1, const Sales_data& sd2)
{
    return sd1.isbn() < sd2.isbn();
}

int main()
{
    Sales_data d1("CppPrimer"), d2("JavaCore"), d3("PythonCookBook"),
        d4("CppCore"), d5("AwesomeCPP");
    std::vector<Sales_data> v{d1, d2, d3, d4, d5};
    std::sort(v.begin(), v.end(), compareIsbn);

    for (const auto& element : v) std::cout << element.isbn() << " ";
    std::cout << std::endl;
}
