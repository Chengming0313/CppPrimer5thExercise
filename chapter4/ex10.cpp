#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{

    int i;
    // 从标准输入中读取整数，直到遇到42
    while ( cin >> i && i != 42 )
    {
    }

    return 0;
}