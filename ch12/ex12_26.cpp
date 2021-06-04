//
//  ex12_26.cpp
//
//  Created by Tang Chengming on 06/03/2021
//
//  @Brief  用 aoolcate 重写 p427 中的程序。

#include <iostream>
#include <memory>
#include <string>

int main() {
    std::allocator<std::string> alloc;

    std::cout << "请输入你要输入的 string 的个数: ";
    int n = 0;
    std::cin >> n;
    if (n < 0) {
        std::cerr << "个数不能小于 0\n";
    }
    // step.1 申请了 n 个 string 的空间.
    auto const  p = alloc.allocate(n);
    auto        q = p;
    std::string str;
    while (std::cin >> str) {
        // step.2 初始化 q 指向的内存.
        alloc.construct(q++, str);
    }

    std::cout << "成功创建了" << q - p << "个 string.\n";
    for (auto cur = p; cur < q; ++cur) {
        std::cout << cur - p << " " << *cur << "\n";
    }
    // step.3 从后面依次销毁构造的 string 对象.
    while (q != p) {
        alloc.destroy(--q);
    }
    // step.4 释放所有申请的空间.
    alloc.deallocate(p, n);

    return 0;
}
