//
//  ex13_05.cpp
//
//  Created by Tang Chengming on 2021/7/13.
//
//  @Brief  ex13.5 添加 copy ctor， 拷贝动态内存，而不是简单的拷贝 ps 指针
//          ex13.8 添加 copy op=
//          ex13.11 添加 dtor
//          ex13.22 添加一些功能函数
//
//

#include <string>
#include <iostream>

class HasPtr {
public:
    // --------------------------- 构造函数 ---------------------------

    HasPtr(std::string const &str) : ps_(new std::string(str)), i_(0) {}

    // --------------------------- 拷贝控制 ---------------------------

    // 13.5 copy ctor
    HasPtr(HasPtr const &rhs) : ps_(new std::string(*rhs.ps_)), i_(rhs.i_) {}

    // 13.8 copy op=
    HasPtr &operator=(HasPtr const &rhs) {
        auto newPs = new std::string(*rhs.ps_);     // 拷贝 rhs 中的动态内存
        delete ps_;                                 // 释放 this 中的旧内存
        ps_ = newPs;                                // 让 ps_ 指向新内存
        i_ = rhs.i_;                                // 为 i_ 赋值
        return *this;                               // 返回此对象的一个引用
    }

    // 13.11 dtor
    ~HasPtr() {
        // 释放 ps 占有的资源
        std::cout << "delete ps[" << ps_ << "]" << std::endl;
        delete ps_;
    }


    // --------------------------- Debug ---------------------------
    void printPs() {
        std::cout << "ps[" << ps_ << "]" << std::endl;
    }

    // ex13.22

    HasPtr &operator=(std::string const &str){
        delete ps_;
        ps_ = new std::string(str);
        i_ = 0;
        return *this;
    }

    std::string &operator*() {
        return *ps_;
    }

private:
    std::string *ps_;
    int i_;
};

int main() {

    HasPtr h("h");
    HasPtr h2(h);
    HasPtr h3 = h;

    h2 = "h2";
    h3 = "h3";

    std::cout << *h << std::endl;
    std::cout << *h2 << std::endl;
    std::cout << *h3 << std::endl;

    return 0;
}

