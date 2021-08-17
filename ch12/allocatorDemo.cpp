//
//  allocatorDemo.cpp
//
//  Created by Tang Chengming on 2021/8/3.
//
//  @Brief  
//

#include <memory>
#include <string>
#include <iostream>

int main() {
    std::allocator<std::string> strAlloc;
    auto const p = strAlloc.allocate(10);
    auto q = p;
    for(int i = 0; i < 10; ++i) {
        strAlloc.construct(q++, std::to_string(i));
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    while (q != p) {
        strAlloc.destroy(--q);
    }

    strAlloc.deallocate(p, 10);
    return 0;
}
