//
// Created by rui ding on 2025/12/22.
//

#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;

    std::cout << "initial size=" << v.size()
              << " capacity=" << v.capacity() << '\n';

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        std::cout << "push " << i
                  << " size=" << v.size()
                  << " capacity=" << v.capacity() << '\n';
    }
}
