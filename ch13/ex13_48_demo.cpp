//
//  ex13_47_demo.cpp
//
//  Created by Tang Chengming on 2021/8/5.
//
//  @Brief  观察 vector<String> 多次调用 push_back 函数，String 进行拷贝的次数。
//          拷贝的次数 = 拷贝构造函数调用次数 + 拷贝赋值运算符调用次数

#include "ex13_44_String.h"

#include <vector>
#include <iostream>

int main() {
    String s1("1");
    String s2("2");
    String s3("3");
    String s4("4");
    String s5("5");

    std::vector<String> strVec;
    // ex13.47 push_back 5 次, copy ctor 会被调用 5 + (1 + 2 + 4) = 12 次
    // ex13.50 push_back 5 次, copy ctor 会被调用 5 次用来拷贝构造push_back的实参, move ctor 会被调用 1 + 2 + 4 = 7次用来在扩容中移动元素
    strVec.push_back(s1);
    strVec.push_back(s2);
    strVec.push_back(s3);
    strVec.push_back(s4);
    strVec.push_back(s5);
    std::cout << "size: " << strVec.size() << " capacity: " << strVec.capacity() << std::endl;

//    strVec.push_back(std::move(s1));

    return 0;
}