//
//  ex13_18.cpp
//
//  Created by Tang Chengming on 2021/7/14.
//
//  @Brief  ex13.18 定义Employee
//

#include <iostream>
#include <string>

class Employee {
    // ------------------- Debug -------------------

    friend std::ostream &operator<<(std::ostream &, Employee const &);
public:
    // ------------------- 构造函数 -------------------

    Employee() : id_(sId_++), name_("anonymous") {}

    Employee(std::string name) : id_(sId_++), name_(name) {}

    // ------------------- 拷贝控制 -------------------

    // copy ctor
    Employee(Employee const &rhs) : id_(sId_++), name_(rhs.name_) {}

    // copy op=
    Employee &operator=(Employee const &rhs) {
        name_ = rhs.name_;
        return *this;
    }

    // dtor
    ~Employee() = default;
private:
    static unsigned sId_;

    unsigned id_;
    std::string name_;
};

unsigned Employee::sId_ = 0;

// print Employee data member
std::ostream &operator<<(std::ostream &os, Employee const &rhs) {
    return os << "(" << rhs.name_ << ", " << rhs.id_ << ")";
}

int main() {
    {
        std::cout << "测试构造函数: " << std::endl;
        Employee e1, e2("张三");
        // (anonymous, 0)
        // (张三, 0)
        std::cout << e1 << std::endl;
        std::cout << e2 << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "测试 copy ctor 以及 copy op= : " << std::endl;
        Employee e1("张三"), e2("李四"), e3(e1);
        e2 = e1;
        // (张三, 2)
        // (张三, 3)
        // (张三, 4)
        std::cout << e1 << std::endl;
        std::cout << e2 << std::endl;
        std::cout << e3 << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
