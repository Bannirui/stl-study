//
// Created by rui ding on 2025/12/22.
//

#include <vector>
#include <iostream>

void print(const auto comment, const auto& container)
{
    auto size = std::size(container);
    std::cout << comment << "{ ";
    for (const auto& element : container) {
        std::cout << element << (--size ? ", " : " ");
    }
    std::cout << "}\n";
}

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

    std::vector<int> x{1, 2, 3}, y, z;
    // 这是C++里一个非常特殊 优先级极高的规则 只要出现auto x = { ... } 推导结果必然是std::initializer_list<T>
    const auto w = {4, 5, 6, 7};

    std::cout << "Initially:\n";
    print("x = ", x);
    print("y = ", y);
    print("z = ", z);

    std::cout << "Copy assignment copies data from x to y:\n";
    y = x;
    print("x = ", x);
    print("y = ", y);

    std::cout << "Move assignment moves data from x to z, modifying both x and z:\n";
    z = std::move(x);
    print("x = ", x);
    print("z = ", z);

    std::cout << "Assignment of initializer_list w to z:\n";
    z = w;
    print("w = ", w);
    print("z = ", z);
}
