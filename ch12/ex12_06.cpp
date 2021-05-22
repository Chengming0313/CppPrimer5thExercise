//
//  ex12_06.cpp
//
//  Created by Tang Chengming on 05/19/2021
//
//  @Brief  编写函数, 返回一个动态分配的 int 的 vector. 将此 vector 传递给另一个函数,
//          这个函数读取标准输入, 将读入的值保存在 vector 中.
//          再将 vector 传递给第三个函数, 打印元素. 记得 delete vector.

#include <iostream>
#include <vector>

std::vector<int> *factory() {
    return new std::vector<int>;
}

void readVec(std::vector<int> *pVec) {
    int x;
    while (std::cin >> x) {
        pVec->push_back(x);
    }
}

void printVec(std::vector<int> *pVec) {
    for (auto n : *pVec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    auto pVec = factory();
    readVec(pVec);
    printVec(pVec);
    delete pVec;
    return 0;
}
