#include <vector>
#include <iostream>
#include <memory>

/**
 * Generate and return a shared pointer of a vector of integers.
 * @return a shared pointer to a std::vector<int> indicates the vector we generate.
 */
std::shared_ptr<std::vector<int>> vector_generator() {
    return std::make_shared<std::vector<int>>();
}

/**
 * Set vector's elements by the sequence of integers from the standard input.
 * @param vec a shared pointer to a std::vector<int> indicates the vector we generate.
 */
void vector_values_set(std::shared_ptr<std::vector<int>> vec) {
    std::cout << "Please input a sequence of integers to set the vector's value!\n";
    int eachElement;
    while (std::cin >> eachElement) {
        vec -> emplace_back(eachElement);
    }
}

/**
 * Print vector's each element.
 * @param vec a shared pointer to a std::vector<int> indicates the vector we generate.
 */
void vector_values_print(std::shared_ptr<std::vector<int>> vec) {
    for (const int &element : *vec)
        std::cout << element << ' ';
}

int main() {
    std::shared_ptr<std::vector<int>> myVec = vector_generator();
    vector_values_set(myVec);
    vector_values_print(myVec);
    return 0;
}
