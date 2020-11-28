#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    /* ca中没有存放'\0'空字符，必然会发生数组越界 */
    const char  ca[] = { 'h', 'e', 'l', 'l', 'o' };
    const char *cp   = ca;
    while ( *cp )
    {
        cout << *cp << endl;
        ++cp;
    }

    return 0;
}