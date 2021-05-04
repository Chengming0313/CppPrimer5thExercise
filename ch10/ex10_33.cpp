//
//  ex10_33.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  编写程序，接受三个参数, 一个输入文件名和两个输出文件名. 读取输入文件, 将读到的奇数以及
//          偶数存入不同的输出文件, 每个奇数后跟一个空格, 偶数独占一行.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

void func(std::string infile, std::string outfile1, std::string outfile2) {
    std::ifstream              ifs(infile);
    std::ofstream              ofs1(outfile1), ofs2(outfile2);
    std::istream_iterator<int> inIter(ifs), eofIter;
    std::ostream_iterator<int> outIter1(ofs1, " "), outIter2(ofs2, "\n");
    // std::vector<int>           c(inIter, eofIter);
    // std::for_each(c.cbegin(), c.cend(), [](int x) { std::cout << x << " "; });
    while (inIter != eofIter) {
        if (*inIter & 0x1)
            *outIter1 = *inIter;
        else
            *outIter2 = *inIter;
        ++inIter;
    }
}

int main() {
    func("F:\\Project\\CodeProject\\CODE_CPP\\CPP_Primer\\ch10\\data\\ex10_33.in",
         "F:\\Project\\CodeProject\\CODE_CPP\\CPP_Primer\\ch10\\data\\ex10_33_1.out",
         "F:\\Project\\CodeProject\\CODE_CPP\\CPP_Primer\\ch10\\data\\ex10_33_2.out");
    return 0;
}
