//
// Created by rui ding on 2026/1/4.
//

#include <iostream>

int main() {
    {
        std::deque<int> d;
    }
    {
        // initializer list构造
        std::deque<int> d = {7, 5, 16, 8};
        d.push_back(1);
    }
    return 0;
}
