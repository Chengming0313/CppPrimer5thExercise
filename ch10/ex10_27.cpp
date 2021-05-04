//
//  ex10_27.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  编写程序, 使用 unique_copy 将一个 vector 中不重复的元素拷贝到一个初始为空的 list 中.

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

template <typename Sequence>
void print(Sequence seq) {
    for (auto n : seq) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> ivec{ 1, 2, 1, 3, 4, 5, 5, 6 };
    std::sort(ivec.begin(), ivec.end());
    std::list<int> lst;
    // lst 初始为空，不能使用普通迭代器
    std::unique_copy(ivec.cbegin(), ivec.cend(), std::back_inserter(lst));

    print(lst);
    return 0;
}
