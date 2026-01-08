//
// Created by rui ding on 2026/1/8.
//

#include <iostream>
#include <string>
#include <map>

void print_map(std::string_view comment, const std::map<std::string, int> &m) {
    std::cout << comment;
    for (const auto &[key, value]: m) {
        std::cout << '[' << key << "] = " << value << "; ";
    }
    std::cout << '\n';
}

int main() {
    // 1 先构造initializer_list
    // 2 触发的是map的无参构造方法
    // 3 然后调用map的=重载
    std::map<std::string, int> m{
            {"RAM", 20},
            {"GPU", 15},
            {"CPU", 10},
    };

    print_map("1) Initial map: ", m);

    m["CPU"] = 25; // update an existing value
    m["SSD"] = 30; // insert a new value
    print_map("2) Updated map: ", m);

    // Using operator[] with non-existent key always performs an insert
    std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    print_map("4) Updated map: ", m);

    m.erase("GPU");
    print_map("5) After erase: ", m);

    std::erase_if(m, [](const auto &pair) { return pair.second > 25; });
    print_map("6) After erase: ", m);
    std::cout << "7) m.size() = " << m.size() << '\n';

    m.clear();
    std::cout << std::boolalpha << "8) Map is empty: " << m.empty() << '\n';
}
