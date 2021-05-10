//
//  ex11_08.cpp
//
//  Created by Tang Chengming on 05/10/2021
//
//  @Brief  编写一个程序在一个 vector 而不是 set 中保存不重复的单词.
//          使用 set 的优点是什么.
//
//  @Answer  set 中插入、查询以及删除元素的时间复杂度都是 O(logN)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename Sequence>
void print(Sequence seq) {
    for (auto const &n : seq) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> ivec{ "tom", "jack", "david", "tom", "jack" };

    std::vector<std::string> vset;

    for (auto n : ivec) {
        if (std::find(vset.cbegin(), vset.cend(), n) == vset.cend()) {
            vset.push_back(n);
        }
    }

    print(vset);

    return 0;
}
