//
// Created by rui ding on 2026/1/8.
//

#include <forward_list>
#include <iostream>

template<typename T>
std::ostream &operator<<(std::ostream &s, const std::forward_list<T> &v) {
    s.put('{');
    for (char comma[]{'\0', ' ', '\0'}; const auto &e: v)
        s << comma << e, comma[0] = ',';
    return s << "}\n";
}

template<typename T>
void print(std::string msg, const std::forward_list<T> &l) {
    std::cout << msg << ": " << l;
}

int main() {
    {
        std::forward_list<int> l;
        l.push_front(1);
        l.push_front(2);
        print("1", l);
    }
}
