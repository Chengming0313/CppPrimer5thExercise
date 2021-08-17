#include <iostream>
#include <vector>
#include <memory>

class A {
public:
    A(int data = 0) : data_(data) {
        std::cout << "ctor" << std::endl;
    }

    A(A const &rhs) :data_(rhs.data_) {
        std::cout << "copy ctor from " << &rhs << " to " << this << std::endl;
    }

    A(A &&rhs) :data_(rhs.data_) {
        std::cout << "move ctor from " << &rhs << " to " << this << std::endl;
    }

//    A(A &&rhs)= delete;
private:
    int data_;
};

A createA() {
    std::cout << "create A" << std::endl;
    return A();
}

int main(int argc, char const *argv[])
{
    A a = createA();

    return 0;
}
