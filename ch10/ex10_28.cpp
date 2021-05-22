//
//  ex10_28.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  在一个 vector 中保存 1 到 9, 分别使用 inserter back_inserter
//          front_inserter将其拷贝到三个其它容器中.

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
    std::vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::list<int>   c1, c2, c3;
    std::copy(ivec.cbegin(), ivec.cend(), std::inserter(c1, c1.begin()));
    std::copy(ivec.cbegin(), ivec.cend(), std::back_inserter(c2));
    std::copy(ivec.cbegin(), ivec.cend(), std::front_inserter(c3));
    print(c1);
    print(c2);
    print(c3);
    return 0;
}
