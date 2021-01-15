#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{

  std::vector<std::string> vec{"cat", "dog", "mouse", "distance", "clever", "helicopter", "jellyfish"};

  int result = std::count_if(vec.cbegin(), vec.cend(), [] (const std::string& str)  {return str.size() > 6;});

  std::cout << "Altogether there are " << result << " words whose sizes are greater than 6\n";
  
  return 0;
}
