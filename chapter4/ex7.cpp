#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/* 溢出是指计算的结果超出该类型所能表达的范围 */
int main()
{
    unsigned short us = 0xffff + 1;
    int            i  = 0x7fffffff + 1;
    long long      ll = 0x7fffffffffffffff + 1;

    cout << us << " " << i << " " << ll << endl;

    return 0;
}