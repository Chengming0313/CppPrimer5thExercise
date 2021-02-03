// 输入两个整数，输出两个整数之间的所有整数
#include <iostream>

int main()
{
    int v1, v2;
    std::cin >> v1 >> v2;

    while (v1 <= v2)
    {
        std::cout << v1 << " ";
        ++v1;
    }
    std::cout << std::endl;
    return 0;
}