//
//  ex11_28.cpp
//
//  Created by Tang Chengming on 05/13/2021
//
//  @Brief

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<std::string, std::vector<int>>                 m;
    std::map<std::string, std::vector<int>>::const_iterator item = m.find("hello");

    return 0;
}
