//
//  ex11_14.cpp
//
//  Created by Tang Chengming on 05/11/2021
//
//  @Brief

#include <iostream>
#include <map>
#include <utility>
#include <vector>

using Pair = std::pair<std::string, std::string>;
using FamilyMap = std::map<std::string, std::vector<Pair>>;

void printMap(FamilyMap map) {
    for (auto const &p : map) {
        std::cout << "姓氏 : " << p.first << ":\n";
        for (auto const &n : p.second) {
            std::cout << "名: " << n.first << ", 生日: " << n.second << std::endl;
        }
    }
}

void insertFamily(FamilyMap &map, std::string familyName, std::vector<Pair> children) {
    map[familyName] = children;
}

void insertChild(FamilyMap &map, std::string familyName, Pair child) {
    map[familyName].push_back(child);
}

int main() {
    FamilyMap fmap{
        { "Zhang", { { "DE", "1999-01-21" }, { "GHA", "1999-01-21" }, { "GAJ", "1999-01-21" } } },
        { "Wang", { { "XGD", "1999-01-21" }, { "HG", "1999-01-21" }, { "GADG", "1999-01-21" } } },
    };
    std::cout << "before add\n";
    printMap(fmap);

    std::cout << "\nadd familyName LI\n";
    insertFamily(fmap, "LI",
                 { { "GFDH", "1999-01-21" }, { "JGH", "1999-01-21" }, { "RTY", "1999-01-21" } });
    printMap(fmap);

    std::cout << "\nadd childName for LI\n";
    insertChild(fmap, "LI", { "CXB", "1999-01-21" });
    printMap(fmap);

    return 0;
}
