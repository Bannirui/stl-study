#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;
    std::cout << "push前size=" << stack.size() << std::endl;
    stack.push(1);
    std::cout << "push后size=" << stack.size() << std::endl;
    int i = stack.top();
    stack.pop();
    std::cout << "pop后size=" << stack.size() << std::endl;
    std::cout << "i=" << i << std::endl;
    return 0;
}
