//
//  ex10_42.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  使用 list 替代 vector 重写 p343 中的 elimDups.

#include <iostream>
#include <list>
#include <string>

void elimDups(std::list<std::string> &lst) {
    lst.sort();
    lst.unique();
}

template <typename Sequence>
void print(Sequence seq) {
    for (auto n : seq) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<std::string> lst{ "aaa", "aaa", "ccc", "ccc", "bbb" };
    std::cout << "原始序列:\n";
    print(lst);
    elimDups(lst);
    std::cout << "去除重复单词后:\n";
    print(lst);
    return 0;
}
