//
//  ex13_58_demo.cpp
//
//  Created by Tang Chengming on 2021/8/17.
//
//  @Brief  
//


#include <iostream>
#include <vector>
#include <algorithm>

class Foo {
public:
    Foo sorted() && {
        std::cout << "右值引用版本的 sorted" << std::endl;
        std::sort(data_.begin(), data_.end());
        return *this;
    }
#if 0
    Foo sorted() const & {
        std::cout << "ex13.56 左值引用版本的 sorted: " << std::endl;
        Foo ret(*this);
        return ret.sorted();
    }
#endif
    Foo sorted() const & {
        std::cout << "ex13.57 左值引用版本的 sorted: " << std::endl;
        return Foo(*this).sorted();
    }
private:
    std::vector<int> data_;
};


int main() {
    Foo foo;
    foo.sorted();


    return 0;
}