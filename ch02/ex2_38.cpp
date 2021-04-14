#include <iostream>

int main()
{
    int i        = 0;
    const int ci = 0;

    decltype(i) a1 = 0;  // int a1
    auto a2        = i;  // int a2

    decltype(ci) b1 = 0;   // const int b1
    auto b2         = ci;  // int b2
}