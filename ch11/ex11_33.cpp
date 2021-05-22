//
//  ex11_33.cpp
//
//  Created by Tang Chengming on 05/14/2021
//
//  @Brief  实现你自己版本的单词转换函数.

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using Map = std::map<std::string, std::string>;

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

int main() {
    std::ifstream mapFile("F:/Project/CodeProject/CODE_CPP/CPP_Primer/ch11/data/mapFile.txt"),
        inputFile("F:/Project/CodeProject/CODE_CPP/CPP_Primer/ch11/data/inputFile.txt");
    wordTransform(mapFile, inputFile);

    return 0;
}
