#include <iostream>

class A {
public:
    A() {}
    A(int data) : _data(data) {}
    void print() { std::cout << _data << std::endl; }

private:
    int _data = 1;
};

int main() {
    A a1(2), a2;
    a1.print();
    a2.print();
    return 0;
}