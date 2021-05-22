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
    std::set_new_handler(noMoreMemory);
    for (int i = 0; i < 100; ++i) {
        int *pBigDataArray = new int[100000000];
    }
}