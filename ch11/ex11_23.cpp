//
//  ex11_23.cpp
//
//  Created by Tang Chengming on 05/12/2021
//
//  @Brief  用 multimap 重写 11.2.1 节 (p378) 中的统计孩子姓与名的 map.
//
//  @See  ex11_07.cpp

#include <iostream>
#include <map>
#include <utility>
#include <vector>

using Pair = std::pair<std::string, std::vector<std::string>>;
using FamilyMap = std::multimap<std::string, std::vector<std::string>>;

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

int main() {
    FamilyMap fmap{
        { "Zhang", { "HFA", "GHAO", "GASHO" } },
        { "Wang", { "QTH", "OHJG", "GHOS" } },
        { "Wang", { "GHH", "OSG", "BNHTH" } },
    };
    printMap(fmap);

    return 0;
}
