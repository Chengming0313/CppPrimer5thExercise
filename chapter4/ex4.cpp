#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/* 先找优先级，再从左先右结合（算术运算符都是左结合） */
int main()
{
    cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;
    cout << ( ( 12 / 3 ) * 4 ) + ( 5 * 15 ) + ( ( 24 % 4 ) / 2 ) << endl;

    return 0;
}