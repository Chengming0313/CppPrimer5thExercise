//
//  ex12_32.h
//
//  Created by Tang Chengming on 2021/6/5.
//
//  @Brief  重写 TextQuery QueryResult, 用 StrBlob 代替 vector<string>.
//

#ifndef CPP_PRIMER5_EX12_32_H
#define CPP_PRIMER5_EX12_32_H

#include <fstream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <set>
#include "ex12_22.h"  // StrBlob

class QueryResult;

class TextQuery {
    using Lineno = StrBlob::SizeType;
public:
    explicit TextQuery(std::ifstream &ifs);

    QueryResult query(std::string const &) const;

private:
    StrBlob _context;
    std::unordered_map<std::string, std::shared_ptr<std::set<Lineno>>> linenoMap_;
    std::unordered_map<std::string, Lineno> timesMap_;
};


class QueryResult {
    using Lineno = StrBlob::SizeType;

    friend std::ostream &print(std::ostream &, QueryResult const &);

public:
    QueryResult(std::string key, StrBlob context,
                std::shared_ptr<std::set<Lineno>> pLinenoSet, Lineno times)
            : key_(key), _context(context), _pLinenoSet(pLinenoSet),
              _times(times) {}

private:
    std::string key_;
    StrBlob _context;
    std::shared_ptr<std::set<Lineno>> _pLinenoSet;
    Lineno _times;
};

std::ostream &print(std::ostream &, QueryResult const &);


#endif //CPP_PRIMER5_EX12_32_H
