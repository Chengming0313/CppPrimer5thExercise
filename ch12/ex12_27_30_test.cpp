//
//  ex12_27_30_test.cpp
//
//  Created by Tang Chengming on 06/04/2021
//
//  @Brief  TextQuery QueryResult 单元测试文件

#include "ex12_27_30.h"

#include <iostream>

void runQueries(std::ifstream &ifs) {
    TextQuery tq(ifs);
    while (true) {
        std::cout << "enter word to look for or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        print(std::cout, tq.query(s));
    }
}

int main() {
    std::ifstream ifs("CppPrimer5th/ch12/data/ex12_27.in");
    runQueries(ifs);
    return 0;
}
