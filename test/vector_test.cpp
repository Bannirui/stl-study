//
// Created by rui ding on 2025/12/22.
//

#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        std::cout << "push " << i << " size=" << v.size() << " capacity=" << v.capacity() << '\n';
    }
    std::cout << "initial size=" << v.size() << " capacity=" << v.capacity() << '\n';

    // 构造大小是3的vector 里面放了3个元素0
    std::vector<int> v1(3);
    std::cout << "v1 size=" << v1.size() << " capacity=" << v1.capacity() << '\n';
    for (int i=0, sz=v1.size(); i<sz; ++i) {
        std::cout << "v1的内容 " << i << " " << v1.at(i) << '\n';
    }

    // 构造大小是3的vector 里面放了3个元素0
    std::vector<int> v2{1,2,3};
    std::cout << "v2 size=" << v2.size() << " capacity=" << v2.capacity() << '\n';
    for (int i=0, sz=v2.size(); i<sz; ++i) {
        std::cout << "v2的内容 " << i << " " << v2.at(i) << '\n';
    }

    // 大小3的空vector
    std::vector<int> v3;
    v3.reserve(3);
    std::cout << "v3 size=" << v3.size() << " capacity=" << v3.capacity() << '\n';
    for (int i=0, sz=v3.size(); i<sz; ++i) {
        std::cout << "v3的内容 " << i << " " << v2.at(i) << '\n';
    }
}
