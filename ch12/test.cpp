#include <cstdlib>  // abort
#include <initializer_list>
#include <iostream>
#include <memory>
#include <new>
#include <vector>

void noMoreMemory() {
    std::cerr << "Unable to satisify request for memory" << std::endl;
    std::abort();
}

int main() {
    unsigned char ch;
    std::cin >> ch;
    std::cout << ( unsigned )ch << std::endl;
    std::cin >> ch;
    std::cout << ( unsigned )ch << std::endl;
}