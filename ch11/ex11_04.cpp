//
//  ex11_03.cpp
//
//  Created by Tang Chengming on 05/10/2021
//
//  @Brief 扩展 exercise 11.3, 忽略单词大小写和标点.

#include <algorithm>  // remove_if
#include <cctype>     // ispunct
#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {

    auto strip = [](std::string &str) {
        for (auto &ch : str) {
            ch = std::tolower(ch);
        }
        str.erase(std::remove_if(str.begin(), str.end(), static_cast<int (*)(int)>(std::ispunct)),
                  str.end());
    };

    std::map<std::string, int> wordCnt;
    std::set<std::string>      exclude{ "the", "but", "and" };

    std::string word;
    while (std::cin >> word) {
        strip(word);
        if (exclude.find(word) == exclude.cend()) ++wordCnt[word];
    }

    for (auto const &p : wordCnt) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}
