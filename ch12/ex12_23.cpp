//
//  ex12_23.cpp
//
//  Created by Tang Chengming on 05/22/2021
//
//  @Brief  编写一个程序, 连接两个字符串常量, 将结果保存在一个动态分配的 char 数组中.
//          重写这个程序, 连接两个标准库 string 对象.

#include <cstring>
#include <iostream>
#include <string>

// 连接两个字符串常量
void catCString(char const *lhs, char const *rhs) {
    char *str = new char[std::strlen(lhs) + std::strlen(rhs) + 1]();
    std::strcat(str, lhs);
    std::strcat(str, rhs);
    std::cout << str << std::endl;
    delete[] str;
}

// 连接两个标准库 string 类型
void catString(std::string const &lhs, std::string const &rhs) {
    std::string str;
    // str += lhs;
    // str += rhs;
    str.append(lhs);
    str.append(rhs);
    std::cout << str << std::endl;
}

int main() {
    char const *str1 = "hello", *str2 = " world";
    catCString(str1, str2);
    std::string str3("hello"), str4(" world");
    catString(str3, str4);
    return 0;
}
