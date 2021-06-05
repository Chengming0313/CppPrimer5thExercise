//
//  ex12_32_test.cpp
//
//  Created by Tang Chengming on 2021/6/5.
//
//  @Brief  测试重写的 TextQuery QueryResult 类.
//

#include "ex12_32.h"

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
    std::ifstream ifs("../../ch12/data/ex12_27_30.in");
    runQueries(ifs);
    return 0;
}


