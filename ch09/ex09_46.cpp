//
//  ex09_46.cpp
//  cpp primer 5th exercise 9.46
//
//  Created by aozy on 04/16/2021
//
//  @Brief  Rewrite the previous exercise using a position and length to manage the strings.
//          This time use only the insert function.

#include <iostream>
#include <string>

std::string AddPrefixAndSuffix(std::string name, std::string const &prefix,
                               std::string const &suffix) {
    // 使用下标 pos 来插入字符串时，不能通过 [b2, e2) 来插入，直接传入 str 即可。
    name.insert(0, prefix);
    return name.insert(name.size(), suffix);
}

int main() {

    std::string name("Wang");
    std::cout << AddPrefixAndSuffix(name, "Mr.", ", Jr.") << std::endl;

    return 0;
}
