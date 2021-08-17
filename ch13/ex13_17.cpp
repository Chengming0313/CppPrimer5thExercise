//
//  ex13_17.cpp
//
//  Created by Tang Chengming on 2021/7/13.
//
//  @Brief  
//

#include <iostream>
#include <random>

// ex13.13
namespace t1 {
    struct numbered {
        static unsigned index;
        unsigned mysn_;
        numbered() {
            mysn_ = index++;
        }
    };

    unsigned numbered::index = 0;

    void f(numbered s) {
        std::cout << s.mysn_ << std::endl;
    }
}

// ex13.15
namespace t2 {
    struct numbered {
        static unsigned index;
        unsigned mysn_;
        numbered() {
            mysn_ = index++;
        }
        numbered(numbered const &x) {
            mysn_ = index++;
        }
    };

    unsigned numbered::index = 0;

    void f(numbered s) {
        std::cout << s.mysn_ << std::endl;
    }
}

// ex13.16
namespace t3 {
    struct numbered {
        static unsigned index;
        unsigned mysn_;
        explicit numbered() {
            mysn_ = index++;
        }
        numbered(numbered const &x) {
            mysn_ = index++;
        }
    };

    unsigned numbered::index = 0;

    void f(numbered const &s) {
        std::cout << s.mysn_ << std::endl;
    }
}

int main() {
    // ex13.14
    {
        std::cout << "练习 13.14: " << std::endl;
        using namespace t1;
        numbered a, b = a, c = b;
        f(a);
        f(b);
        f(c);
        std::cout << std::endl;
    }
    // ex13.15
    {
        std::cout << "练习 13.15: " << std::endl;
        using namespace t2;
        numbered a, b = a, c = b;
        f(a);
        f(b);
        f(c);
        std::cout << std::endl;
    }
    // ex13.16
    {
        std::cout << "练习 13.16: " << std::endl;
        using namespace t3;
        numbered a, b = a, c = b;
        f(a);
        f(b);
        f(c);
        std::cout << std::endl;
    }

    return 0;
}



