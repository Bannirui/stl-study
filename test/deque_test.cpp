//
// Created by rui ding on 2026/1/4.
//

#include <iomanip>
#include <iostream>

#include "x.h"

template<typename T>
std::ostream &operator<<(std::ostream &s, const std::deque<T> &v) {
    s.put('{');
    for (char comma[]{'\0', ' ', '\0'}; const auto &e: v) {
        s << comma << e, comma[0] = ',';
    }
    return s << "}\n";
}

template<typename T>
void print(std::deque<T> q) {
    std::cout << q;
}
template<typename T>
void print(std::string hint, std::deque<T> q) {
    std::cout << hint << ": " << q;
}

int main() {
    {
        std::deque<int> q = {1, 2, 3, 4, 5};
        print("resize前", q);
        q.resize(10);
        print("resize后", q);
    }
    {
        std::deque<int> q{1, 2};
        print("pop_back前", q);
        q.pop_back();
        print("pop_back后", q);
    }
    {
        std::deque<std::string> letters;
        letters.push_back("abc");
        std::string s{"def"};
        letters.push_back(std::move(s));
        std::cout << "std::deque letters holds: ";
        for (auto &&e: letters)
            std::cout << std::quoted(e) << ' ';
        std::cout << "\nMoved-from string s holds: " << std::quoted(s) << '\n';
    }
    {
        std::deque<int> q{1, 2, 3, 4, 5};
        print("erase前", q);
        q.erase(q.begin());
        print("erase后", q);
    }
    {
        std::deque<X> q;
        q.emplace_back("one");
    }
    {
        std::deque<X> q;
        q.emplace(q.end(), "one");
    }
    {
        std::deque<int> q = {1, 2, 3};
        print("insert前", q);
        q.insert(q.begin(), 9);
        print("insert后", q);
    }
    {
        std::deque<int> q = {1, 2, 3, 4, 5};
        print("clear前", q);
        q.clear();
        print("clear后", q);
    }
    {
        std::deque<int> q{1, 2, 3, 4, 5};
        std::cout << "max_size=" << q.max_size() << std::endl;
    }
    {
        std::deque<int> q{1, 2, 3, 4, 5};
        std::cout << q.size() << std::endl;
    }
    {
        std::deque<int> q;
        std::cout << q.empty() << std::endl;
    }
    {
        std::deque<int> q = {1, 3};
        int i = q.back();
        std::cout << i << std::endl;
    }
    {
        std::deque<int> q = {1, 3};
        int i = q.front();
        std::cout << i << std::endl;
    }
    {
        std::deque<int> q = {1, 2, 3};
        print(q);
        q[4] = 88;
        print(q);
    }
    {
        std::deque<int> q = {1, 2, 3, 4, 5};
        print(q);
        q.at(1) = 88;
        print(q);
    }
    {
        std::deque<int> q;
        auto a = q.get_allocator();
    }
    {
        std::deque<int> q;
        q.assign(2, 8);
        print(q);
        q.assign(3, 5);
        print(q);
    }
    {
        std::deque<int> x = {1, 2, 3, 4, 5};
        print(x);
        std::deque<int> y;
        y = x;
        print(y);
    }
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
