//
//  12_2_2.cpp
//
//  Created by Tang Chengming on 05/22/2021
//
//  @Brief

#include <iostream>
#include <memory>
#include <string>
#include <vector>

void test1() {
    std::allocator<std::string> alloc;
    auto const                  p = alloc.allocate(5);
    auto                        q = p;
    // terminate by exception
    std::cout << *q << std::endl;
}

void test2() {
    std::allocator<int> alloc;
    auto const          p = alloc.allocate(5);
    auto                q = p;
    // run successfully
    std::cout << *q << std::endl;
}

// allocator example
void test3() {
    // step.1 allocate memory
    std::allocator<std::string> alloc;
    auto const                  p = alloc.allocate(3);

    // step.2 constuct objects
    auto q = p;  // q : pointer to the next momory to construct
    alloc.construct(q++);
    alloc.construct(q++, 3, 'x');
    alloc.construct(q++, "cmt");

    // step.3 destroy objects
    while (q != p) {
        std::cout << "\"" << *(--q) << "\"" << std::endl;
        alloc.destroy(q);
    }

    // step.4 deallocate memory
    alloc.deallocate(p, 3);
}

// 未初始化(构造)内存中创建对象
void test4() {
    std::allocator<int> alloc;
    std::vector<int>    vec{ 1, 2, 3, 4, 5 };
    auto const          p = alloc.allocate(vec.size() * 2);
    auto const          q = std::uninitialized_copy(vec.cbegin(), vec.cend(), p);
    std::uninitialized_fill_n(q, vec.size(), 100);
    for (int i = 0; i < vec.size() * 2; ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    test4();
    return 0;
}
