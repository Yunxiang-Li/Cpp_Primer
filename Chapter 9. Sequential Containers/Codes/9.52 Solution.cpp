#include <iostream>
#include <stack>
#include <cstring>

void findAndReplaceParenthesizedPart(std::stack<char>& cStack, const char* str) {
  unsigned seen{0};

  for (unsigned i = 0; i != strlen(str); ++i) {
    cStack.push(str[i]);
    if (str[i] == '(')
      ++seen;
    else if (str[i] == ')' && seen) {
      while (cStack.top() != '(')
        cStack.pop();
      cStack.pop();
      cStack.push('#');
      --seen;
    }
  }
}

int main() {
  std::stack<char> myStack{};
  const char* cStr{"This is() ()an me(())ss(age)())!"};
  std::cout << "Current string content is: " << *cStr << '\n';
  std::cout << "All parenthesized part will be replaced by #" << '\n';
  findAndReplaceParenthesizedPart(myStack, cStr);

  while (!myStack.empty()) {
    std::cout << myStack.top();
    myStack.pop();
  }

  return 0;
}
