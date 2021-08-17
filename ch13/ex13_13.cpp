//
//  ex13_13.cpp
//
//  Created by Tang Chengming on 2021/7/13.
//
//  @Brief  
//

#include <iostream>
#include <vector>

struct X {
    X() {std::cout << "ctor" << std::endl;}
    X(X const &) {std::cout << "copy ctor" << std::endl;}
    X &operator=(X const &rhs) {
        if (&rhs == this) {
            return *this;
        }
        std::cout << "copy op=" << std::endl;
        return *this;
    }
    ~X() {std::cout << "dtor" << std::endl;}
};

void passByValueFunc(X x) {}
void passByRefFunc(X &x) {}

void test() {
    std::cout << "局部变量: " << std::endl;
    // ctor
    X a;
    std::cout << std::endl;

    std::cout << "传递对象给非引用类型形参: " << std::endl;
    // copy ctor
    // dtor
    passByValueFunc(a);
    std::cout << std::endl;

    std::cout << "传递对象给引用类型形参: " << std::endl;
    passByRefFunc(a);
    std::cout << std::endl;

    std::cout << "动态分配: " << std::endl;
    // ctor
    auto pX = new X();
    std::cout << std::endl;

    std::cout << "添加到容器中: " << std::endl;
    std::vector<X> xVec;
    // copy ctor
    xVec.push_back(a);
    std::cout << std::endl;

    std::cout << "释放之前分配的动态内存: " << std::endl;
    // dtor
    delete pX;
    std::cout << std::endl;

    std::cout << "拷贝初始化和赋值: " << std::endl;
    // copy ctor
    X b = a;
    // copy op=
    a = b;
    std::cout << std::endl;

    std::cout << "程序结束: " << std::endl;
    // dtor : a
    // dtor : b
    // dtor : xVec
}

int main() {
    test();

    return 0;
}