#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// 改成前置递增运算符，程序的结果会不符合预期
// 1. 第一个元素访问不到，会从第2个元素开始输出
// 2. 可能发生数组越界问题
// 3. 可能输出负数

int main()
{
    vector< int > ivec  = { 1, 2, -1 };
    vector< int > ivec2 = { 1, 2, 3 };  // 访问ivec2会发生数组越界问题
    auto          vbeg  = ivec2.cbegin();
    while ( vbeg != ivec2.cend() && *vbeg >= 0 )
    {
        // 前置运算符输出的是后一个元素
        cout << *++vbeg << endl;
    }

    return 0;
}