//
//  ex12_07.cpp
//
//  Created by Tang Chengming on 05/19/2021
//
//  @Brief  重做 exercise 12.6 使用 shared_ptr, 而不是内置指针.

#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> factory() {
    return std::make_shared<std::vector<int>>();
}

void readVec(std::shared_ptr<std::vector<int>> pVec) {
    int x;
    while (std::cin >> x) {
        pVec->push_back(x);
    }
}

void printVec(std::shared_ptr<std::vector<int>> pVec) {
    for (auto n : *pVec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    auto pVec = factory();
    readVec(pVec);
    printVec(pVec);
    return 0;
}
