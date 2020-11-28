#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// ptr -> int *
// ival -> int
// vec -> vector<int>

int main()
{
    /* a */
    // ptr != 0 && *ptr++
    // 判断ptr是否是空指针，同时判断ptr指向的int对象是不是0，不是的话ptr指向下一个int对象

    /* b */
    // ival++ && ival
    // 判断ival以及ival+1是否都不为0，这里 && 规定了求值顺序

    /* c */
    // vec[ival++] <= vec[ival]
    // 这个表达式不正确，因为 <= 没有规定求值顺序，所以不能保证左边的表达式先执行
    // 更改：vec[ival] <= vec[ival + 1]

    return 0;
}