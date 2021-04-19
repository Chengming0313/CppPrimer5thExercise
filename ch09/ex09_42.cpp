//
//  ex09_42.cpp
//
//  Created by Tang Chengming on 04/16/2021
//
//  @Brief  Given that you want to read a character at a time into a string, and you know that you
//          need to read at least 100 characters, how might you improve the performance of your
//          program?

#include <iostream>
#include <string>

int main() {
    std::string str;
    // 使用　reserve 提取为 str 分配 100，减少扩容操作
    str.reserve(100);

    for (int i = 0; i < 105; ++i) {
        str.push_back('x');
    }

    return 0;
}
