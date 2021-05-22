//
//  ex12_24.cpp
//
//  Created by Tang Chengming on 05/22/2021
//
//  @Brief  编写一个程序, 从标准输入读入一个字符串, 存入一个动态分配的字符数组.
//          描述你的程序如何处理变长输入. 测试你的程序, 输入一个超出你分配的数组长度的字符串.

#include <iostream>

int main() {
    std::cout << "how many character do you want to input?\n";
    int sz;
    std::cin >> sz;
    char *strBuffer = new char[sz + 1]();
    // 忽略上一次输入留下的换行符
    std::cin.ignore();
    // get 遇到 换行符会终止运行, 即使还没有读取 sz 个字符
    std::cin.get(strBuffer, sz + 1);
    std::cout << "size of string: " << sz << std::endl;
    std::cout << strBuffer << std::endl;
    return 0;
}
