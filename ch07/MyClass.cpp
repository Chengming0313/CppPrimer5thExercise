#include <iostream>

struct A {
    int  _data;
    void print() { std::cout << "hello\n"; }
};

class B {
    int  _data;
    void print() { std::cout << "hello\n"; }
};

int main() {
    A a;
    B b;
    std::cout << a._data << '\n';
    a.print();
//    std::cout << b._data << '\n';  // error
//    b.print();                     // error

    return 0;
}