//
//  MessageFolderDemo.cpp
//
//  Created by Tang Chengming on 2021/8/3.
//
//  @Brief  
//

#include "ex13_34_37_Message.h"
#include "ex13_36_Folder.h"

#include <iostream>

int main() {

    Folder f1("目录1"), f2("目录2");
    Message m1("m1"), m2("m2"), m3("m3");
    m1.save(f1);
    m1.save(f2);
    m2.save(f1);
    m2.save(f2);
    m3.save(f1);
    f1.printDebug();
    f2.printDebug();

    std::cout << "移除部分消息\n";
    m2.remove(f2);
    m3.remove(f1);
    f1.printDebug();
    f2.printDebug();

    return 0;
}


