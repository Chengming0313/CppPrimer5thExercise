//
//  ex12_32.cpp
//
//  Created by Tang Chengming on 2021/6/5.
//
//  @Brief  ex12_32.h 的实现文件
//

#include "ex12_32.h"

#include <algorithm>
#include <memory>
#include <sstream>

TextQuery::TextQuery(std::ifstream &ifs) {
    Lineno lineno{0};
    for (std::string line; std::getline(ifs, line); ++lineno) {
        _context.pushBack(line);
        std::istringstream iss(line);
        for (std::string word; iss >> word;) {
            word.erase(
                    std::remove_if(word.begin(), word.end(), static_cast<int (*)(int)>(&std::ispunct)),
                    word.cend());
            // 这里必须是引用类型
            auto &ps = linenoMap_[word];
            if (!ps) {
                ps = std::make_shared<std::set<Lineno>>();
            }
            ps->insert(lineno);
            ++timesMap_[word];
        }
    }
}

// 查询 key 在文章中出现的次数、行号
QueryResult TextQuery::query(std::string const &key) const {
    static std::shared_ptr<std::set<Lineno>> noData = std::make_shared<std::set<Lineno>>();
    if (timesMap_.find(key) != timesMap_.cend()) {
        // 这里不能用 [] 来访问元素
        timesMap_.at(key);
    }
    auto item = linenoMap_.find(key);
    if (item == linenoMap_.cend()) {
        return QueryResult(key, _context, noData, 0);
    }
    return QueryResult(key, _context, linenoMap_.at(key), timesMap_.at(key));
}

inline std::string makePlural(std::string const &str, std::size_t times, std::string const &end) {
    return times > 1 ? str + end : str;
}

// 向 os 中打印 qr
std::ostream &print(std::ostream &os, QueryResult const &qr) {
    os << qr.key_ << " occurs " << qr._times << makePlural(" time", qr._times, "s") << "\n";
    for (auto const &lineno : *(qr._pLinenoSet.get())) {
        ConstStrBlobPtr p(qr._context, lineno);
        os << "\t(line " << lineno + 1 << ") " << p.deref() << "\n";
    }
    return os;
}
