//
//  ex12_28.cpp
//
//  Created by Tang Chengming on 06/03/2021
//
//  @Brief  编写程序实现文本查询, 不要定义类来管理数据.

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

inline std::string makePlural(std::string const &str, std::size_t times, std::string const &end) {
    return times > 1 ? str + end : str;
}

void print(std::string const &key, int times, std::set<int> const &linenoSet,
           std::vector<std::string> const &context) {
    std::cout << key << " occurs " << times << makePlural(" time", times, "s") << "\n";
    for (auto cur = linenoSet.cbegin(); cur != linenoSet.cend(); ++cur) {
        // lineno 从 0 开始, 而外界编号从 1 开始.
        std::cout << "\t"
                  << "(line " << *cur + 1 << ") " << context[*cur] << "\n";
    }
}

void runQueries(std::ifstream &ifs) {
    std::vector<std::string> context;
    std::string              lineStr;
    while (std::getline(ifs, lineStr)) {
        context.push_back(lineStr);
    }
    std::unordered_map<std::string, std::set<int>> linenoMap;
    std::unordered_map<std::string, int>           timesMap;

    while (true) {
        std::cout << "enter word to look for or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        auto l = linenoMap.find(s);
        auto t = timesMap.find(s);
        if (l != linenoMap.cend() && t != timesMap.cend()) {
            print(s, t->second, l->second, context);
            continue;
        }
        int           times = 0;
        std::set<int> linenoSet;
        for (int lineno = 0; lineno < static_cast<int>(context.size()); ++lineno) {
            std::istringstream iss(context.at(lineno));
            std::string        word;
            while (iss >> word) {
                if (word == s) {
                    ++times;
                    linenoSet.insert(lineno);
                }
            }
        }
        timesMap.insert({ s, times });
        linenoMap.insert({ s, linenoSet });
        print(s, times, linenoSet, context);
    }
}

int main() {
    std::ifstream ifs("CppPrimer5th/ch12/data/ex12_27.in");
    runQueries(ifs);
    return 0;
}
