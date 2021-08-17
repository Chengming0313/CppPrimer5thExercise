//
//  HasPtr.h
//
//  Created by Tang Chengming on 2021/8/1.
//
//  @Brief  
//

#include <string>

#ifndef CPP_PRIMER5_HASPTR_H
#define CPP_PRIMER5_HASPTR_H

// 定义类行为像值的HasPtr：副本和原对象完全独立
class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
public:
    // 构造函数
    HasPtr(std::string s = std::string()) : ps_(new std::string(s)) {}

    // 拷贝构造函数
    HasPtr(HasPtr const &rhs) : ps_(new std::string(*rhs.ps_)), i_(rhs.i_) {}

    // 拷贝赋值运算符
    HasPtr &operator=(HasPtr rhs);

    // 析构函数
    ~HasPtr() {
        delete ps_;
    }

    // --------------- Debug ---------------
    void pushBack(char ch) {
        ps_->push_back(ch);
    }

    std::string strData() const{
        return *ps_;
    }
private:
    int i_;
    std::string *ps_;
};

inline HasPtr &HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;   // 返回本对象
}

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
}

#endif //CPP_PRIMER5_HASPTR_H
