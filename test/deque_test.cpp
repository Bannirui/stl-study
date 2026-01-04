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
