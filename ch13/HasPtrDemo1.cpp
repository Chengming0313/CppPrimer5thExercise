//
//  HasPtrDemo1.cpp
//
//  Created by Tang Chengming on 2021/8/1.
//
//  @Brief  
//

#include "HasPtr1.h"
#include <iostream>

void test2() {
    HasPtr hp1("hp1"), hp2("hp2");
    swap(hp1, hp2);
    std::cout << hp1.strData() << " " << hp2.strData() << std::endl;
}


void test1() {
    HasPtr hp1("hp"), hp2(hp1), hp3;    // 拷贝构造
    hp3 = hp2;                          // 拷贝赋值运算符
    // 自我赋值
    hp3 = hp3;

    hp1.pushBack('1');
    hp2.pushBack('2');
    hp3.pushBack('3');
    std::cout << hp1.strData() << " " << hp2.strData() << " " << hp3.strData() << std::endl;
}

int main() {
    test1();

    return 0;
}
