#include <iostream>
#include <list>

template<typename T>
std::ostream &operator<<(std::ostream &s, const std::list<T> &v) {
    s.put('{');
    for (char comma[]{'\0', ' ', '\0'}; const auto &e: v)
        s << comma << e, comma[0] = ',';
    return s << "}\n";
}

template<typename T>
void print_list(std::string msg, const std::list<T> &l) {
    std::cout << msg << ": " << l;
}

int main() {
    {
        std::list<int> l;
        l.assign(3, 2);
        print_list("6", l);
    }
    {
        std::initializer_list<int> x = {1, 2, 3};
        std::list<int> l = {5, 6};
        // list对象已经构造好 触发了=运算符重载
        l = x;
        print_list("5", l);
    }
    {
        std::initializer_list<int> x = {1, 2};
        // 此时list对象还没构造 因此触发的是list的构造函数 参数是初始化列表版本的构造函数
        std::list<int> l = x;
        print_list("5", l);
    }
    {
        //   ->1<->2<->3<-
        //   |           |
        //   |____end____|
        std::list<int> l{1, 2, 3};
        print_list("4", l);
    }
    {
        std::list<int> l(3, 1);
        print_list("3", l);
    }
    {
        std::list<int> l(3);
        print_list("2", l);
    }
    {
        std::list<std::string> l;
        print_list("1", l);
    }
}
