//
//  ex10_29.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  编写程序, 使用一个流迭代器读取一个文本文件, 存入 std::vector<std::string>.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void test1() {
    std::ifstream                      ifs("CPP_Primer\\ch10\\data\\ex10_29.in");
    std::istream_iterator<std::string> inIter(ifs), eofIter;

    std::vector<std::string> svec(inIter, eofIter);
    std::copy(svec.cbegin(), svec.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

void test2() {
    std::ifstream                      ifs("CPP_Primer\\ch10\\data\\ex10_29.in");
    std::istream_iterator<std::string> inIter(ifs), eofIter;

    std::vector<std::string> svec;
    while (inIter != eofIter) {
        svec.push_back(*inIter++);
    }
    std::copy(svec.cbegin(), svec.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}
