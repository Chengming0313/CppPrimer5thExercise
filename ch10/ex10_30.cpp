//
//  ex10_30.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  使用流迭代器 sort 以及 copy 从标准输入读取一个整数序列, 将其排序, 并将结果写入
//          标准输出.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::istream_iterator<int> inIter(std::cin), eofIter;
    std::vector<int>           ivec(inIter, eofIter);
    std::sort(ivec.begin(), ivec.end());
    std::copy(ivec.cbegin(), ivec.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
