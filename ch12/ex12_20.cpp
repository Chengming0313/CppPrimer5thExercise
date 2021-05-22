//
//  ex12_20.cpp
//
//  Created by Tang Chengming on 05/20/2021
//
//  @Brief  逐行读入一个输入文件, 将内容存入一个 StrBlob 中, 用一个
//          StrBlobPtr 打印出 StrBlob 中的每个元素.

#include "ex12_19.h"

#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream ifs("CppPrimer5th\\ch12\\data\\ex12_20.in");
    std::string   str;
    StrBlob       sb;
    // 逐行读入
    while (std::getline(ifs, str)) {
        sb.pushBack(str);
    }

    for (auto sbp = sb.begin(); sbp != sb.end(); sbp.incr()) {
        std::cout << sbp.deref() << std::endl;
    }
    return 0;
}
