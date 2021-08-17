//
//  ex13_30.cpp
//
//  Created by Tang Chengming on 2021/7/15.
//
//  @Brief  为 HasPtr 添加 swap 函数
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HasPtr {
public:

    // 13.5 copy ctor
    HasPtr(HasPtr const &hasPtr) : ps_(new std::string(*(hasPtr.ps_))), i_(hasPtr.i_) {}

    // 13.8 copy op=
    HasPtr &operator=(HasPtr const &rhs) {
        if (&rhs == this) {
            return *this;
        }
        delete ps_;
        this->ps_ = new std::string(*(rhs.ps_));
        this->i_ = rhs.i_;
        return *this;
    }

    // 13.11 dtor
    ~HasPtr() {
        // 释放 ps 占有的资源
        std::cout << "delete ps[" << ps_ << "]" << std::endl;
        delete ps_;
    }

    // ctor
    HasPtr(const std::string &s = std::string())
            : ps_(new std::string(s)), i_(0) {}

    // debug
    void printPs() {
        std::cout << "ps[" << ps_ << "]" << std::endl;
    }

    // 解引用运算符
    std::string &operator*() {
        return *ps_;
    }

    // ex 13.31
    // op <
    bool operator<(HasPtr const &rhs) const{
        return *ps_ < *rhs.ps_;
    }

private:
    // ex13.30
    friend void swap(HasPtr &lhs, HasPtr &rhs) {
        using std::swap;
        std::cout << "swap: " << *lhs.ps_ << ", " << *rhs.ps_ << std::endl;
        swap(lhs.ps_, rhs.ps_);
        swap(lhs.i_, rhs.i_);
    }

    std::string *ps_;
    int i_;
};

void ex30() {
    HasPtr hp1("hp1"), hp2(hp1), hp3;
    hp3 = hp1;

    hp2 = HasPtr("hp2");
    hp3 = HasPtr("hp3");

    std::cout << "hp1: " << *hp1 << std::endl;
    std::cout << "hp2: " << *hp2 << std::endl;
    std::cout << "hp3: " << *hp3 << std::endl;

    swap(hp1, hp2);
    std::cout << "hp1: " << *hp1 << std::endl;
    std::cout << "hp2: " << *hp2 << std::endl;
    std::cout << "hp3: " << *hp3 << std::endl;
}

void ex31() {
    std::vector<HasPtr> hpVec;
    hpVec.reserve(100);

    for (int i = 0; i < 100; ++i) {
        hpVec.emplace_back(std::to_string(i));
    }

    std::sort(hpVec.begin(), hpVec.end());
}

int main() {
    ex31();

    return 0;
}

