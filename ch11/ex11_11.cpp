//
//  ex11_11.cpp
//
//  Created by Tang Chengming on 05/10/2021
//
//  @Brief  不适用 decltype 重新定义 p379 的 bookstore.

#include "SalesData.h"

#include <iostream>
#include <set>

// 使用 using 声明与 compare 相同的函数指针类型
using pf = bool (*)(SalesData const &, SalesData const &);

bool compareIsbn(SalesData const &lhs, SalesData const &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main() {
    // std::multiset<SalesData, decltype(compareIsbn) *> bookstore(compareIsbn);
    std::multiset<SalesData, pf> multiset(compareIsbn);
    return 0;
}
