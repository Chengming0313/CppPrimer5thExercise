//
//  ex10_37.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  给定一个包含 10 个元素的 vector, 将位置 3 到 7 之间的元素按逆序拷贝到一个
//          list.

#include <iostream>
#include <iterator>  // back_inserter、ostream_inserter
#include <list>
#include <vector>

int main() {
    std::vector<int> ivec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::list<int>   lst;
    std::copy(ivec.crbegin() + 2, ivec.crend() - 3, std::back_inserter(lst));
    std::copy(lst.cbegin(), lst.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
