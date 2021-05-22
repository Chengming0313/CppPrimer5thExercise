//
//  ex10_07.cpp
//  cpp primer 5th exercise 10.7
//
//  Created by Tang Chengming on 04/25/2021
//
//  @Brief

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::list;
using std::vector;

template <typename T>
void print(T t) {
    for (auto n : t) {
        cout << n << " ";
    }
    cout << endl;
}

void case1() {
    vector<int> vec;
    list<int>   lst;
    int         i;
    while (cin >> i) {
        lst.push_back(i);
    }
    // fixed: 使用 resize 来确保 vec 的大小（这里不能使用 reserve ）
    vec.resize(lst.size());
    // error: vec 不能保证能够容纳所有的元素
    copy(lst.cbegin(), lst.cend(), vec.begin());

    print(vec);
}

void case2() {
    vector<int> vec;
    // 不会出错, 但是不会起到预期的作用
    // vec.reserve(10);
    // fixed: 确保 vec 存放了 10 个元素
    vec.resize(10);
    fill_n(vec.begin(), 10, 0);
    print(vec);
}

int main() {
    case1();
    case2();
    return 0;
}
