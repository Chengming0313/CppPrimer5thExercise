//
//  ex11_07.cpp
//
//  Created by Tang Chengming on 05/10/2021
//
//  @Brief  定义一个 map, key 是家庭的姓, value 是一个 vector, 保存家中孩子们的名.
//          编写代码, 实现添加新的家庭以及向已有家庭中添加新的孩子.

#include <iostream>
#include <map>
#include <utility>
#include <vector>

using Pair = std::pair<std::string, std::vector<std::string>>;
using FamilyMap = std::map<std::string, std::vector<std::string>>;

void printMap(FamilyMap map) {
    for (auto const &p : map) {
        std::cout << "家中姓氏 : " << p.first << ":\n";
        std::cout << "孩子名 : ";
        for (auto const &n : p.second) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
}

void insertFamily(FamilyMap &map, std::string familyName, std::vector<std::string> childrenName) {
    map.insert(Pair(familyName, childrenName));
}

void insertChild(FamilyMap &map, std::string familyName, std::string childName) {
    map[familyName].push_back(childName);
}

int main() {
    FamilyMap fmap{
        { "Zhang", { "三", "四", "五" } },
        { "Wang", { "三", "四", "五" } },
    };
    std::cout << "before add\n";
    printMap(fmap);

    std::cout << "\nadd familyName D\n";
    insertFamily(fmap, "D", { "001", "002", "003" });
    printMap(fmap);

    std::cout << "\nadd childName for D\n";
    insertChild(fmap, "D", "xxx");
    printMap(fmap);

    return 0;
}
