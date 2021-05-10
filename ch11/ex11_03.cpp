//
//  ex11_03.cpp
//
//  Created by Tang Chengming on 05/10/2021
//
//  @Brief 编写你自己的单词计数程序.

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
    std::map<std::string, int> wordCnt;
    std::set<std::string>      exclude{ "the", "but", "and" };

    std::vector<std::string> words{ "the", "example", "but", "example" };
    std::string              word;
    while (std::cin >> word) {
        if (exclude.find(word) == exclude.cend()) ++wordCnt[word];
    }
    std::cout << wordCnt.size() << std::endl;
    for (auto const &p : wordCnt) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}
