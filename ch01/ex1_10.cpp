// 使用--运算符，输出10到0之间的整数
#include <iostream>

int main()
{
    int i = 10;
    while (i >= 0)
    {
        std::cout << i << std::endl;
        --i;
    }
    return 0;
}