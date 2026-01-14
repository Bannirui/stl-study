//
// Created by rui ding on 2026/1/14.
//

#include <iostream>

int main() {
    {
        // 指定小根堆
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        q.push(3);
        q.push(1);
        q.push(2);
        for (int i = 0, sz = q.size(); i < sz; ++i) {
            int x = q.top();
            q.pop();
            std::cout << x << "\t";
        }
        std::cout << std::endl;
    }
    {
        // 默认大根堆
        std::priority_queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        for (int i = 0, sz = q.size(); i < sz; ++i) {
            int x = q.top();
            q.pop();
            std::cout << x << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}
