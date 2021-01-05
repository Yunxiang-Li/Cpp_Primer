#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::vector<std::string> vec256(256, "a");
  std::vector<std::string> vec512(512, "b");
  std::vector<std::string> vec1000(1000, "c");
  std::vector<std::string> vec1048(1048, "d");

  std::vector<std::string> vec1;
  for (const std::string& element : vec256)
    vec1.emplace_back(element);
  vec1.resize(vec1.size() + vec1.size() / 2);
  std::cout << "Current vector's size: " << vec1.size() << '\n';
  std::cout << "Current vector's capacity: " << vec1.capacity() << '\n';

  std::vector<std::string> vec2;
  for (const std::string& element : vec512)
    vec2.emplace_back(element);
  vec2.resize(vec2.size() + vec2.size() / 2);
  std::cout << "Current vector's size: " << vec2.size() << '\n';
  std::cout << "Current vector's capacity: " << vec2.capacity() << '\n';

  std::vector<std::string> vec3;
  for (const std::string& element : vec1000)
    vec3.emplace_back(element);
  vec3.resize(vec3.size() + vec3.size() / 2);
  std::cout << "Current vector's size: " << vec3.size() << '\n';
  std::cout << "Current vector's capacity: " << vec3.capacity() << '\n';

  std::vector<std::string> vec4;
  for (const std::string& element : vec1048)
    vec4.emplace_back(element);
  vec4.resize(vec4.size() + vec4.size() / 2);
  std::cout << "Current vector's size: " << vec4.size() << '\n';
  std::cout << "Current vector's capacity: " << vec4.capacity() << '\n';

  return 0;
}
