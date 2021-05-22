//
//  ex10_25.cpp
//
//  Created by Tang Chengming on 05/03/2021
//
//  @Brief  使用 check_size 以及 bind 重写 exercise 10.18 中 partition 版本的 biggies.

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

// exercise 10.9
void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto endUnique = std::unique(words.begin(), words.end());
    words.erase(endUnique, words.end());
}

bool check_size(std::string const &str, int size) {
    return static_cast<int>(str.size()) >= size;
}

// 统计所有长度不小于 sz 的单词（重复单词只计算一次）
void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    // step.1 字典序升序排列，并删除重复元素
    elimDups(words);
    // step.2 使用 std::partition 按长度划分 words
    auto endRes = std::partition(words.begin(), words.end(), std::bind(check_size, _1, sz));
    // step.3 打印长度不小于 sz 的单词数目以及满足条件的单词
    int cnt = endRes - words.begin();
    std::cout << cnt << std::endl;
    for (int i = cnt; i > 0; --i) {
        std::cout << *(endRes - i) << " ";
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
