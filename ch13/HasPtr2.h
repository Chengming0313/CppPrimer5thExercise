//
//  HasPtr2.h
//
//  Created by Tang Chengming on 2021/8/1.
//
//  @Brief  
//

#include <string>
#include <cstddef>

#ifndef CPP_PRIMER5_HASPTR2_H
#define CPP_PRIMER5_HASPTR2_H

class HasPtr {
public:
    // 构造函数，引用计数初始化为 1
    HasPtr(std::string s = std::string()) : ps_(new std::string(s)), i_(0), use_(new std::size_t(1)) {}

    // 拷贝构造函数
    HasPtr(HasPtr const &rhs) : ps_(rhs.ps_), i_(rhs.i_), use_(rhs.use_) {
        ++*use_;
    }

    // 拷贝赋值运算符
    HasPtr &operator=(HasPtr const &rhs);

    // 析构函数
    ~HasPtr() {
        if (--*use_ == 0) {
            delete ps_;
            delete use_;
        }
    }

    // --------------- Debug ---------------
    void pushBack(char ch) {
        ps_->push_back(ch);
    }

    std::string strData() const{
        return *ps_;
    }
private:
    std::string *ps_;
    int i_;
    std::size_t *use_;   // 引用计数
};

inline HasPtr &HasPtr::operator=(HasPtr const &rhs) {
    // 先增加 rhs 的引用计数处理自我赋值的情况
    ++*rhs.use_;
    if (--*use_ == 0) {
        delete ps_;
        delete use_;
    }
    i_ = rhs.i_;
    ps_ = rhs.ps_;
    use_ = rhs.use_;
    return *this;
}

#endif //CPP_PRIMER5_HASPTR2_H
