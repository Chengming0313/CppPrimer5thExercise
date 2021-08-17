//
//  HasPtrDemo2.cpp
//
//  Created by Tang Chengming on 2021/8/1.
//
//  @Brief  
//

#include "HasPtr2.h"

#include <iostream>

int main() {
    HasPtr hp1("hp"), hp2(hp1), hp3;    // 拷贝构造
    hp3 = hp2;                          // 拷贝赋值运算符
    // 自我赋值
    hp3 = hp3;

    hp1.pushBack('1');
    hp2.pushBack('2');
    hp3.pushBack('3');
    std::cout << hp1.strData() << " " << hp2.strData() << " " << hp3.strData() << std::endl;

    return 0;
}
