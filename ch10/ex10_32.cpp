//
//  ex10_32.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  重写1.6节的书店程序, 使用 vector 保存交易记录, 使用不同算法完成处理.
//         sort compareIsbn find accumulate.

#include "Sales_item.h"

#include <algorithm>  // sort copy find_if
#include <fstream>
#include <iostream>
#include <iterator>  // istream_iterator ostream_iterator
#include <numeric>   // accumulate
#include <vector>

bool isShorter(Sales_item const &lhs, Sales_item const &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main() {
    // step.1 从文件中读取书籍销售记录到 vector
    std::ifstream                     ifs("CPP_Primer\\ch10\\data\\ex10_32.in");
    std::istream_iterator<Sales_item> inIter(ifs), eofIter;
    std::vector<Sales_item>           c(inIter, eofIter);

    // step2. 排序并输出销售记录
    std::sort(c.begin(), c.end(), isShorter);
    std::cout << "记录: \n";
    std::copy(c.cbegin(), c.cend(), std::ostream_iterator<Sales_item>(std::cout, "\n"));

    // step3. 利用 find_if 以及 accumulate 合并销售记录并输出
    std::cout << "求和: \n";
    for (auto begin = c.cbegin(), end = begin; begin != c.cend(); begin = end) {
        end = std::find_if(begin, c.cend(),
                           [&begin](Sales_item const &x) { return x.isbn() != (*begin).isbn(); });
        Sales_item sum = std::accumulate(begin + 1, end, *begin);
        std::cout << sum << std::endl;
    }

    return 0;
}