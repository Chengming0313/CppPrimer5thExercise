#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int    i;
    double d;
    /* 赋值运算右结合，因此等价于 d = (i = 3.5) */
    d = i = 3.5;
    cout << i << " " << d << endl;
    /* 赋值运算右结合，因此等价于 i = (d = 3.5) */
    i = d = 3.5;
    cout << i << " " << d << endl;

    return 0;
}