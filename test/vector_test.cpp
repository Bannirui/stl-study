//
// Created by rui ding on 2025/12/22.
//

#include <iostream>
#include <vector>

void print(const auto comment, const auto &container) {
    auto size = std::size(container);
    std::cout << comment << "{ ";
    for (const auto &element: container) {
        std::cout << element << (--size ? ", " : " ");
    }
    std::cout << "}\n";
}

template<typename T>
void vector_info(const std::vector<T> &v) {
    std::cout << "vector info: 元素地址=" << v.data() << " size=" << v.size() << " cap=" << v.capacity() << "\n";
}

class MyTemp {
public:
    int a;
    int b;
    std::string c;

    MyTemp(int a, int b, std::string s) : a(a), b(b), c(std::move(s)) {}

    MyTemp(MyTemp &&other) : a(other.a), b(other.b), c(std::move(other.c)) {}

    MyTemp &operator=(const MyTemp &other) = default;
};

std::ostream &operator<<(std::ostream &os, const MyTemp &v) {
    os << "{a=" << v.a << ", b=" << v.b << "}";
    return os;
}

int main() {
    {
        std::vector<MyTemp> v;
        print("emplace_back before: ", v);
        v.emplace_back(MyTemp(1, 2, "hello"));
        print("emplace_back after: ", v);
    }
    {
        std::vector<MyTemp> v;
        print("emplace before: ", v);
        v.emplace(v.begin(), MyTemp(1, 2, "hello"));
        print("emplace after: ", v);
    }
    {
        std::vector<int> x = {1, 2, 3, 4, 5};
        print("erase before:", x);
        x.erase(x.begin());
        print("erase after:", x);
        x.erase(x.begin(), x.begin() + 1);
        print("erase after2:", x);
        x.erase(x.begin(), x.begin() + 2);
        print("erase after3:", x);
    }
    {
        std::vector<int> v(5);
        auto num = v.insert(v.begin() + 1, 100);
        vector_info(v);
        std::cout << *num << "\n";
    }
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        vector_info(v);
        v.clear();
        vector_info(v);
    }
    {
        std::vector<int> v;
        std::cout << "capacity=" << v.capacity() << "\n";
    }
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        vector_info(v);
        v.reserve(2);
        vector_info(v);
    }
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        std::cout << "v1 max_size=" << v.max_size() << std::endl;
        std::vector<long long> v2 = {1, 2, 3, 4, 5};
        std::cout << "v2 max_size=" << v2.max_size() << std::endl;
    }
    {
        std::vector<int> v = {1, 2};
        std::cout << "size=" << v.size() << "\n";
    }
    {
        std::vector<int> v;
        std::cout << "empty=" << v.empty() << std::endl;
    }
    {
        std::vector<int> v = {1};
        std::cout << "empty=" << v.empty() << std::endl;
    }
    {
        std::vector<int> v(1);
        std::cout << "data=" << v.data() << "\n";
    }
    {
        std::vector<int> v;
        v.push_back(2);
        std::cout << "vector back=" << v.back() << "\n";
    }
    {
        std::vector<int> v(3);
        int num = v.front();
        std::cout << "vector front: " << num << "\n";
    }
    {
        std::vector<int> v;
        v.assign(1, 2);
        vector_info(v);
        auto x = v.get_allocator();
        // x.deallocate(v.data(), 2);
    }

    {
        std::vector<int> x(10);
        std::cout << "size=" << x.size() << " cap=" << x.capacity() << "\n";
        x.assign(2, 9);
        print("赋值了2个9", x);
        std::cout << "size=" << x.size() << " cap=" << x.capacity() << "\n";
    }

    {
        std::vector<int> x{1, 2, 3}, y;
        y = x;
        print("x = ", x);
        print("y = ", y);
    }

    {
        // 构造
        std::vector<int> x;
    }

    {
        // 构造大小是3的vector 里面放了3个元素0
        std::vector<int> v1(3);
        std::cout << "v1 size=" << v1.size() << " capacity=" << v1.capacity() << '\n';
        for (int i = 0, sz = v1.size(); i < sz; ++i) {
            std::cout << "v1的内容 " << i << " " << v1.at(i) << '\n';
        }
    }
    {
        // 构造大小是3的vector 里面放了3个元素0
        std::vector<int> v2{1, 2, 3};
        std::cout << "v2 size=" << v2.size() << " capacity=" << v2.capacity() << '\n';
        for (int i = 0, sz = v2.size(); i < sz; ++i) {
            std::cout << "v2的内容 " << i << " " << v2.at(i) << '\n';
        }
    }

    {
        // 大小3的空vector
        std::vector<int> v3;
        v3.reserve(3);
        std::cout << "v3 size=" << v3.size() << " capacity=" << v3.capacity() << '\n';
        for (int i = 0, sz = v3.size(); i < sz; ++i) {
            std::cout << "v3的内容 " << i << " " << v3.at(i) << '\n';
        }
    }

    {
        // 拷贝赋值支持initializer_list
        std::vector<int> x;
        x = {1, 2};
    }

    {
        std::vector<int> xx(5);
        // 自己拷贝给自己 会return asap
        xx = xx;
    }

    {
        // 这是C++里一个非常特殊 优先级极高的规则 只要出现auto x = { ... } 推导结果必然是std::initializer_list<T>
        const auto w = {4, 5, 6, 7};
    }

    // 析构函数
    {
        std::vector<int> v1;
    }
}
