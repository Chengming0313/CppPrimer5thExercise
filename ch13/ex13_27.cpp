//
//  ex13_27.cpp
//
//  Created by Tang Chengming on 2021/7/14.
//
//  @Brief  引用计数版本的 HasPtr
//

#include <cstddef>
#include <string>
#include <iostream>

class HasPtr {
public:
    // 构造函数
    explicit HasPtr(std::string const &s = std::string()) : ps_(new std::string(s)), i_(0), use_(new std::size_t(1)) {}

    // copy ctor
    HasPtr(HasPtr const &x) : ps_(x.ps_), i_(x.i_), use_(x.use_) {
        ++(*x.use_);
    }

    // copy op=
    HasPtr &operator=(HasPtr const &rhs) {
        // 必须先对 rhs 的引用计数加1, 防止自我赋值出错
        ++*rhs.use_;
        if (--*use_ == 0) {
            delete ps_;
            delete use_;
        }
        use_ = rhs.use_;
        ps_ = rhs.ps_;
        i_ = rhs.i_;
        return *this;
    }

    // dtor
    ~HasPtr() {
        if (--*use_ == 0) {
            delete ps_;
            delete use_;
        }
    }

    char &data() {
        return (*ps_)[i_];
    }

private:
    std::string *ps_;  // 字符串指针
    int i_;            // 字符串下标
    std::size_t *use_; // 引用计数
};

int main() {
    HasPtr p1("hello world");
    HasPtr p2(p1), p3;
    p3 = p2;

    std::cout << p1.data() << std::endl;
    std::cout << p2.data() << std::endl;
    std::cout << p3.data() << std::endl;

    p1.data() = '1';

    std::cout << p1.data() << std::endl;
    std::cout << p2.data() << std::endl;
    std::cout << p3.data() << std::endl;

    return 0;
}

