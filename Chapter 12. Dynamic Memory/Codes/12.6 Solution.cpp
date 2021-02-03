#include <vector>
#include <iostream>

/**
 * Generate and return a pointer of a dynamic vector of integers.
 * @return a pointer to a std::vector<int> indicates the vector we generate.
 */
std::vector<int>* dynamic_vector_generator() {
    std::vector<int>* vec = new std::vector<int>();
    return vec;
}

/**
 * Set vector's elements by the sequence of integers from the standard input.
 * @param vec a pointer to a std::vector<int> indicates the vector we generate.
 */
void vector_values_set(std::vector<int>* vec) {
    std::cout << "Please input a sequence of integers to set the vector's value!\n";
    int eachElement;
    while (std::cin >> eachElement) {
        vec -> emplace_back(eachElement);
    }
}

/**
 * Print vector's each element.
 * @param vec a pointer to a std::vector<int> indicates the vector we generate.
 */
void vector_values_print(std::vector<int>* vec) {
    for (const int &element : *vec)
        std::cout << element << ' ';
}

int main() {
    std::vector<int>* myVec = dynamic_vector_generator();
    vector_values_set(myVec);
    vector_values_print(myVec);
    delete myVec;
    return 0;
}
