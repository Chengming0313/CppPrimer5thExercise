#include <iostream>
#include <vector>

class A {
public:
    A(int data = 0) : _data(data) {}  // 自定义默认构造函数
    void printData() { std::cout << _data << std::endl; }

private:
    int _data;
};

int main() {
    // 1. 对 aggregate type 进行 list initialization
    // 首先逐个初始化，不够的进行 value initialization
    int arr1[] = { 1, 2, 3 };   // 没有 value initialization
    int arr2[5] = { 1, 2, 3 };  // 内置类型 value initialization

    for (auto i : arr1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (auto i : arr2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> c1 = { "123", "456", "789" };
    for (auto s : c1) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    A a1{};
    A a2{ 9 };

    a1.printData();
    a2.printData();

    // 非 aggregate type 进行 list initialization
    // 与 () 作用相同

    /* A  a1{};
    A  a2 = {};
    A *a3 = new A{};

    a1.printData();
    a2.printData();
    a3->printData();
    A{}.printData();
    (new A{})->printData(); */

    return 0;
}