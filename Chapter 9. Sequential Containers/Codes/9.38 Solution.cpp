#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec;
  std::cout << "Empty vector's size: " << vec.size() << '\n';
  std::cout << "Empty vector's capacity: " << vec.capacity() << '\n';

  std::cout << "Now add 5 elements" << '\n';
  vec.emplace_back(1);
  vec.emplace_back(2);
  vec.emplace_back(3);
  vec.emplace_back(4);
  vec.emplace_back(5);
  std::cout << "Current vector's size: " << vec.size() << '\n';
  std::cout << "Current vector's capacity: " << vec.capacity() << '\n';

  std::cout << "Now add 3 more elements" << '\n';
  vec.emplace_back(6);
  vec.emplace_back(7);
  vec.emplace_back(8);
  std::cout << "Current vector's size: " << vec.size() << '\n';
  std::cout << "Current vector's capacity: " << vec.capacity() << '\n';

  std::cout << "Now add 1 more element" << '\n';
  vec.emplace_back(9);
  std::cout << "Current vector's size: " << vec.size() << '\n';
  std::cout << "Current vector's capacity: " << vec.capacity() << '\n';

  std::cout << "Now call shrink_to_fit function" << '\n';
  vec.shrink_to_fit();
  std::cout << "Current vector's size: " << vec.size() << '\n';
  std::cout << "Current vector's capacity: " << vec.capacity() << '\n';

  std::cout << "Now call reserve function" << '\n';
  vec.reserve(16);
  std::cout << "Current vector's size: " << vec.size() << '\n';
  std::cout << "Current vector's capacity: " << vec.capacity() << '\n';

  std::cout << "Now call resize function" << '\n';
  vec.resize(10);
  std::cout << "Current vector's size: " << vec.size() << '\n';
  std::cout << "Current vector's capacity: " << vec.capacity() << '\n';

  return 0;
}
