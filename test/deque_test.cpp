//
// Created by rui ding on 2026/1/4.
//

#include <iostream>

template<typename T>
std::ostream &operator<<(std::ostream &s, const std::deque<T> &v) {
    s.put('{');
    for (char comma[]{'\0', ' ', '\0'}; const auto &e: v) {
        s << comma << e, comma[0] = ',';
    }
    return s << "}\n";
}

int main() {
    {
        std::deque<std::string> d(5, "Mo");
        std::cout << d << std::endl;
    }
    {
        std::deque<int> d1 = {7, 5, 16, 8};
        std::deque<int> d2(d1);
        std::cout << d2 << std::endl;
    }
    {
        std::deque<int> d1 = {7, 5, 16, 8};
        std::deque<int> d2(d1.begin(), d1.end());
        std::cout << d2 << std::endl;
    }
    {
        // initializer list构造
        std::deque<int> d = {7, 5, 16, 8};
        std::cout << d << std::endl;
    }
    {
        // 无参
        std::deque<int> d;
    }
    return 0;
}
