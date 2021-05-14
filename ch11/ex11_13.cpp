//
//  ex11_13.cpp
//
//  Created by Tang Chengming on 05/11/2021
//
//  @Brief

#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename Pv>
void printPv(Pv pv) {
    for (auto p : pv) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}

void m1() {
    std::string                              str;
    int                                      i = 0;
    std::vector<std::pair<std::string, int>> res;
    while (std::cin >> str >> i) {
        std::pair<std::string, int> p{ str, i };
        res.push_back(p);
    }

    printPv(res);
}

void m2() {
    std::string                              str;
    int                                      i = 0;
    std::vector<std::pair<std::string, int>> res;
    while (std::cin >> str >> i) {
        // std::pair<std::string, int> p{ str, i };
        res.push_back(std::make_pair(str, i));
    }

    printPv(res);
}

void m3() {
    std::string                              str;
    int                                      i = 0;
    std::vector<std::pair<std::string, int>> res;
    while (std::cin >> str >> i) {
        // std::pair<std::string, int> p{ str, i };
        res.push_back({ str, i });
    }

    printPv(res);
}

int main() {
    // m1();
    // m2();
    m3();
    return 0;
}
