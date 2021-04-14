#include <iostream>

class A {
public:
    A(int data) : _data(data) { std::cout << "data constructor...\n"; }
    A(A const &x) {
        this->_data = x._data;
        std::cout << "copy constructor...\n";
    }

private:
    int _data;
};

int main() {
    A a = 999;
    A a2 = A(999);

    return 0;
}