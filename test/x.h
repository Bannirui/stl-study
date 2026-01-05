//
// Created by rui ding on 2026/1/5.
//

#pragma once

#include <iostream>
#include <string>

class X {
private:
    std::string s;

public:
    X(std::string str) : s(std::move(str)) { std::cout << " constructed" << std::endl; }
    X(const X &o) : s(o.s) { std::cout << " copy constructed" << std::endl; }
    X(X &&o) : s(std::move(o.s)) { std::cout << " move constructed" << std::endl; }

    X &operator=(const X &o) {
        s = o.s;
        std::cout << " copy assigned" << std::endl;
        return *this;
    }

    X &operator=(X &&o) {
        s = std::move(o.s);
        std::cout << " move assigned" << std::endl;
        return *this;
    }
};
