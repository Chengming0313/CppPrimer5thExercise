//
//  ex12_02.h
//
//  Created by Tang Chengming on 05/18/2021
//
//  @Brief  编写你自己的 StrBlob 类, 包含 const 版本的 front 和 back.
//
//  @Reminder  const 版本的 front 以及 back 可以返回 std::string &, 而不是 std::string const &.
//             但这个与常理相悖.

#ifndef CPP_PRIMER_CMT_12_02
#define CPP_PRIMER_CMT_12_02

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlob {
public:
    using SizeType = std::vector<std::string>::size_type;
    // exercise 12.19 用得到
    friend class StrBlobPtr;

    // 构造函数
    StrBlob() : _data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> li)
        : _data(std::make_shared<std::vector<std::string>>(li)) {}
    SizeType size() const { return _data->size(); }
    bool     empty() const { return _data->empty(); }

    // 添加和删除元素
    void pushBack(std::string const &str) { _data->push_back(str); }
    void popBack();

    // 元素访问
    std::string &      front();
    std::string const &front() const;
    std::string &      back();
    std::string const &back() const;

    // exercise 12.9
    StrBlobPtr begin() {
        return StrBlobPtr(*this);
    }

private:
    std::shared_ptr<std::vector<std::string>> _data;
    void                                      check(SizeType index, std::string const &msg) const;
};

inline void StrBlob::check(SizeType index, std::string const &msg) const {
    if (index >= size()) throw std::out_of_range(msg);
}

inline void StrBlob::popBack() {
    check(0, "popBack on empty StrBlob");
    _data->pop_back();
}

inline std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return _data->front();
}

inline std::string const &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return _data->front();
}

inline std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return _data->back();
}

inline std::string const &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return _data->back();
}

#endif
