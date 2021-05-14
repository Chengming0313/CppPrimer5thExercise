//
//  ex11_38.cpp
//
//  Created by Tang Chengming on 05/14/2021
//
//  @Brief  使用 unordered_map 重写 ex11.3 以及 ex11.33
//
//  @See  ex11_03.cpp ex11_33.cpp

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// 单词计数程序
void wordCount() {
    std::unordered_map<std::string, int> wordCnt;
    std::set<std::string>                exclude{ "the", "but", "and" };

    std::vector<std::string> words{ "the", "example", "but", "example" };
    std::string              word;
    while (std::cin >> word) {
        if (exclude.find(word) == exclude.cend()) ++wordCnt[word];
    }
    std::cout << wordCnt.size() << std::endl;
    for (auto const &p : wordCnt) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}

// 单词转换程序
using Map = std::unordered_map<std::string, std::string>;

Map         buildMap(std::ifstream &mapFile);
std::string transform(std::string const &word, Map const &transMap);

void wordTransform(std::ifstream &mapFile, std::ifstream &inputFile) {
    Map         transMap = buildMap(mapFile);
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::string        word;
        bool               firstWord = true;
        while (lineStream >> word) {
            if (firstWord)
                firstWord = false;
            else
                std::cout << " ";
            std::cout << transform(word, transMap);
        }
        std::cout << std::endl;
    }
}

Map buildMap(std::ifstream &mapFile) {
    Map         transMap;
    std::string line;
    while (std::getline(mapFile, line)) {
        int         pos = line.find(" ");
        std::string key = line.substr(0, pos), value = line.substr(pos + 1);
        transMap[key] = value;
    }
    return transMap;
}

std::string transform(std::string const &word, Map const &transMap) {
    auto item = transMap.find(word);
    if (item != transMap.cend()) {
        return item->second;
    }
    return word;
}

void printMap(Map const &transMap) {
    for (auto const &p : transMap) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
}

void testWordTransform() {
    std::ifstream mapFile("F:/Project/CodeProject/CODE_CPP/CPP_Primer/ch11/data/mapFile.txt"),
        inputFile("F:/Project/CodeProject/CODE_CPP/CPP_Primer/ch11/data/inputFile.txt");
    wordTransform(mapFile, inputFile);
}

int main() {
    testWordTransform();
    wordCount();
    return 0;
}
