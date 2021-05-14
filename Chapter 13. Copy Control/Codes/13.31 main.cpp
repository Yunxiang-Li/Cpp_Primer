#include "HasPtr.hpp"
#include <vector>
#include <algorithm>


int main() {
    std::vector<HasPtr> vec;
    vec.emplace_back(HasPtr{"cat"});
    vec.emplace_back(HasPtr{"dog"});
    vec.emplace_back(HasPtr("banana"));
    vec.emplace_back(HasPtr("apple"));

    std::sort(vec.begin(), vec.end());

    for (HasPtr& element : vec)
        std::cout << *(element.getPs()) << '\n';

    return 0;
}
