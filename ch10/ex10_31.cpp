//
//  ex10_31.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  使用 unique_copy 重写 exercise 10.30 程序.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::istream_iterator<int> inIter(std::cin), eofIter;
    std::vector<int>           ivec(inIter, eofIter);
    std::sort(ivec.begin(), ivec.end());
    std::unique_copy(ivec.cbegin(), ivec.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
