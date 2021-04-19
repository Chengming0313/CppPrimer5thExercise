//
//  ex09_45.cpp
//  cpp primer 5th exercise 9.45
//
//  Created by Tang Chengming on 04/16/2021
//
//  @Brief  Write a funtion that takes a string representing a name and two other
//          strings representing a prefix, such as “Mr.” or “Ms.” and a suffix,
//          such as “Jr.” or “III”. Using iterators and the insert and append functions,
//          generate and return a new string with the suffix and prefix added to the
//          given name.

#include <iostream>
#include <string>

std::string AddPrefixAndSuffix(std::string name, std::string const &prefix,
                               std::string const &suffix) {
    // 使用 iter 来 插入时，不能直接传入 str，需要使用 [b2, e2)
    name.insert(name.begin(), prefix.cbegin(), prefix.cend());
    return name.append(suffix.cbegin(), suffix.cend());
}

int main() {

    std::string name("Wang");
    std::cout << AddPrefixAndSuffix(name, "Mr.", ", Jr.") << std::endl;

    return 0;
}
