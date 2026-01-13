#include <iostream>
#include <string>

int main() {
    {
        int i = 99;
        std::string s = std::to_string(i);
        std::cout << s << std::endl;
    }
    {
        std::string str = "hello";
        std::string s;
        for (auto it = str.cbegin(); it != str.cend(); ++it) {
            s.insert(s.begin(), *it);
        }
        std::cout << s << std::endl;
    }
    {
        std::string s = "hello";
        for (int i = 0, sz = s.size(); i < sz; i++) {
            std::cout << s[i] << std::endl;
        }
    }
    {
        std::string s = "hello";
        for (auto c = s.cbegin(); c != s.cend(); c++) {
            std::cout << *c << std::endl;
        }
    }
    {
        // Creating a string from const char*
        std::string str1 = "hello";
        std::cout << str1 << std::endl;
    }
    return 0;
}
