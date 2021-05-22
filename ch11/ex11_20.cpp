//
//  ex11_20.cpp
//
//  Created by Tang Chengming on 05/12/2021
//
//  @Brief  重写 11.1 节 (p376) 中的单词计数程序, 使用 insert 代替下标操作.
//          你认为哪种操作更容易编写和阅读.
//  @Answer  下标操作更好.

#include <iostream>
#include <map>
#include <string>

// I have had my invitation to this world's festival, and thus my life has been blessed
int main() {
    std::map<std::string, int> wordCnt;

    std::string word;
    while (std::cin >> word) {
        ++wordCnt.insert({ word, 0 }).first->second;
    }
    for (auto const &p : wordCnt) {
        std::cout << p.first << " occurs " << p.second << std::endl;
    }

    return 0;
}
