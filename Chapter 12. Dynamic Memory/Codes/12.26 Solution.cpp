#include <iostream>
#include <string>
#include <memory>

void input_reverse_output_string(int n)
{
    std::allocator<std::string> stringAllocator;
    std::string* const p = stringAllocator.allocate(n);
    std::string str;
    std::string* q = p;
    while (std::cin >> str && q != p + n)
        stringAllocator.construct(q++, str);

    while (q != p) {
        std::cout << *--q << " ";
        stringAllocator.destroy(q);
    }

    stringAllocator.deallocate(p, n);
}

int main()
{
    std::cout << "Input a sequence of at most 5 strings and I will output them in a reverse order!" << '\n';
    input_reverse_output_string(5);
}
