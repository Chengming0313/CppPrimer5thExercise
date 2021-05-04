//
//  ex10_16.cpp
//
//  Created by Tang Chengming on 04/28/2021
//
//  @Brief  使用 lambda 编写你自己版本的 biggies。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// exercise 10.9
void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto endUnique = std::unique(words.begin(), words.end());
    words.erase(endUnique, words.end());
}

// 统计所有长度不小于 sz 的单词（重复单词只计算一次）
void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    // step.1 字典序升序排列，并删除重复元素
    elimDups(words);
    // step.2 保证按长度、字典序升序排列 (长度优先级高于字典序)
    std::stable_sort(
        words.begin(), words.end(),
        [](std::string const &lhs, std::string const &rhs) { return lhs.size() < rhs.size(); });
    // step.3 打印长度不小于 sz 的单词数目以及满足条件的单词
    auto beginRes = std::find_if(words.begin(), words.end(),
                                 [&sz](std::string const &str) { return str.size() >= sz; });
    int  cnt = words.end() - beginRes;
    std::cout << cnt << std::endl;
    for (int i = 0; i < cnt; ++i) {
        std::cout << *(beginRes + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> svec{
        "1234", "1234", "1234", "hello", "hello", "hgkg", "gfhj", "world"
    };

    biggies(svec, 5);

    return 0;
}
