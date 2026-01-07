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
        std::list<std::string> l;
        print_list("1", l);
    }
}
