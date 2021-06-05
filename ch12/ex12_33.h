//
//  ex12_33.h
//
//  Created by Tang Chengming on 2021/6/5.
//
//  @Brief  为 QueryResult 添加 begin end getFile 函数
//

#ifndef CPP_PRIMER5_EX12_33_H
#define CPP_PRIMER5_EX12_33_H


#include <cstddef>
#include <fstream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class QueryResult;

class TextQuery {
    using Lineno = std::vector<std::string>::size_type;

public:
    explicit TextQuery(std::ifstream &ifs);
    QueryResult query(std::string const &) const;

private:
    std::shared_ptr<std::vector<std::string>>                          pContext_;
    std::unordered_map<std::string, std::shared_ptr<std::set<Lineno>>> linenoMap_;
    std::unordered_map<std::string, Lineno>                            timesMap_;
};

class QueryResult {
    using Lineno = std::vector<std::string>::size_type; // 行号类型
    using Iter = std::set<Lineno>::iterator;  // 迭代器类型
    friend std::ostream &print(std::ostream &, QueryResult const &);

public:
    QueryResult(std::string key, std::shared_ptr<std::vector<std::string>> pContext,
                std::shared_ptr<std::set<Lineno>> pLinenoSet, Lineno times)
            : key_(std::move(key)), pContext_(std::move(pContext)), pLinenoSet_(std::move(pLinenoSet)),
              times_(times) {}
    //
    Iter begin() {return pLinenoSet_->begin();}
    Iter end() {return pLinenoSet_->end();}
    std::shared_ptr<std::vector<std::string>> getFile() const {return pContext_;}
private:
    std::string                               key_;
    std::shared_ptr<std::vector<std::string>> pContext_;
    std::shared_ptr<std::set<Lineno>>         pLinenoSet_;
    Lineno                                    times_;
};

std::ostream &print(std::ostream &, QueryResult const &);

#endif //CPP_PRIMER5_EX12_33_H
