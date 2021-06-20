#include "Bulk_quote.hpp"


int main() {
    Quote basic("1234", 5.5);
    Bulk_quote bulk("abc", 5.5, 10, 0.2);

    printTotal(std::cout, basic, 20);
    printTotal(std::cout, bulk, 20);

    return 0;
}
