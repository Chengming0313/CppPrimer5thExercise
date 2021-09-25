//
//  ex14_16_StrBlob.h
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  exercise 14.16 为 StrBlob 定义相等运算符和不相等运算符
//

#ifndef CPP_PRIMER5_EX14_16_STRBLOB_H
#define CPP_PRIMER5_EX14_16_STRBLOB_H

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlob {
    using SizeType = std::vector<std::string>::size_type;

    friend inline bool operator==(StrBlob const &, StrBlob const &);
public:
    // ------------------------- 构造函数 -------------------------

    // 默认初始化
    StrBlob() : spContents_(std::make_shared<std::vector<std::string>>()) {}

    // 列表初始化
    StrBlob(std::initializer_list<std::string> initList)
            : spContents_(std::make_shared<std::vector<std::string>>(initList)) {}

    // ------------------------- 拷贝控制 -------------------------
    // 拷贝控制成员使用合成的即可

    // ------------------------- 功能函数 -------------------------

    SizeType size() const;

    bool empty() const;

    void pushBack(std::string const &);

    void popBack();

    std::string &front();

    std::string &back();

    std::string const &front() const;

    std::string const &back() const;
private:
    std::shared_ptr<std::vector<std::string>> spContents_;

    // ------------------------- 工具函数 -------------------------

    // 检查下标 index 是否越界
    void check(SizeType index, std::string const &msg) const;
};

inline StrBlob::SizeType StrBlob::size() const{
    return spContents_->size();
}

inline bool StrBlob::empty() const {
    return spContents_->empty();
}

inline void StrBlob::pushBack(const std::string &str) {
    spContents_->push_back(str);
}

inline void StrBlob::popBack() {
    // 判断数组是否为空, 为空抛出异常
    check(0, "popBack on empty StrBlob");
    // 不为空, 移除尾元素
    spContents_->pop_back();
}

inline std::string &StrBlob::front() {
    // 判断数组是否为空, 为空抛出异常
    check(0, "front on empty StrBlob");
    // 不为空，返回首元素
    return spContents_->front();
}

inline std::string const &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return spContents_->front();
}

inline std::string const &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return spContents_->back();
}

inline std::string &StrBlob::back() {
    // 判断数组是否为空, 为空抛出异常
    check(0, "back on empty StrBlob");
    // 不为空，返回尾元素
    return spContents_->back();
}

inline void StrBlob::check(SizeType index, std::string const &msg) const {
    if (index >= spContents_->size()) {
        throw std::out_of_range(msg);
    }
}

// ------------------- 定义相等运算符和不相等运算符 -------------------
// 只有当 lhs 以及 rhs 的文本内容相等时, lhs 和 rhs 才相等

inline bool operator==(StrBlob const &lhs, StrBlob const &rhs) {
    return *lhs.spContents_ == *rhs.spContents_;
}

inline bool operator!=(StrBlob const &lhs, StrBlob const &rhs) {
    return !(lhs == rhs);
}

#endif //CPP_PRIMER5_EX14_16_STRBLOB_H
