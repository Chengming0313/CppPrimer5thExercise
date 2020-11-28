#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/* 先找优先级，再从左先右结合（算术运算符都是左结合） */
int main()
{
    /* -86 */
    cout << -30 * 3 + 21 / 5 << endl;
    /* -18 */
    cout << -30 + 3 * 21 / 5 << endl;
    /* 0 */
    cout << -30 / 3 * 21 % 5 << endl;
    /* -2 */
    cout << -30 / 3 * 21 % 4 << endl;

    return 0;
}