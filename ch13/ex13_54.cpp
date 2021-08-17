//
//  ex13_54.cpp
//
//  Created by Tang Chengming on 2021/8/17.
//
//  @Brief  
//

#include <iostream>
#include <algorithm>
#include <string>

class HasPtr {
public:
    HasPtr (std::string s = std::string()) : ps(new std::string(s)), i(0) {}

    HasPtr (HasPtr const &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}

    HasPtr (HasPtr &&rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}

    HasPtr &operator=(HasPtr rhs) {
        std::cout << "版本1: " << std::endl;
        swap(rhs);
        return *this;
    }

    HasPtr &operator=(HasPtr &&rhs) {
        std::cout << "版本2: " << std::endl;
        if (this != &rhs) {
            delete ps;
            ps = rhs.ps;
            i = rhs.i;
            rhs.ps = nullptr;
            rhs.i = 0;
        }
        return *this;
    }

    ~HasPtr() {
        delete ps;
    }

    void swap(HasPtr &rhs) {
        using std::swap;
        swap(this->ps, rhs.ps);
        swap(this->i, rhs.i);
    }
private:
    std::string *ps;
    int i;
};

int main() {
    HasPtr hp1("hp1"), hp2("hp2");
    hp1 = hp2;
    hp1 = std::move(hp2);
    return 0;
}

