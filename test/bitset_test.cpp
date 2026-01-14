#include <bitset>
#include <iostream>

int main() {
    {
        // 10个二进制位
        std::bitset<10> b;
        std::cout << b << std::endl;
        // 设置低1位为1 set的第2个参数默认true
        b.set(1);
        std::cout << "set(1): " << b << std::endl;
        b.set(1, 0);
        std::cout << "set(1,0): " << b << std::endl;
        // 设置低3位为1
        b.set(3);
        std::cout << "set(3): " << b << std::endl;
        b.set();
        std::cout << "set(): " << b << std::endl;
        b.reset();
        std::cout << "reset(): " << b << std::endl;
    }
    return 0;
}
