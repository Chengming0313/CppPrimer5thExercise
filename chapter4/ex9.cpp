#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{

    const char *cp = "hello world";
    // 先判断cp是不是空指针，因为cp非空，继续判断cp指向的字符是不是空字符，因为*cp为'h'，因此条件为true
    if ( cp && *cp )
    {
    }

    return 0;
}