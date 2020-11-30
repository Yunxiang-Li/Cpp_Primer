#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  std::string str;

    str = argv[1] + std::string(" ") + argv[2];

  std::cout << str << std::endl;
}
