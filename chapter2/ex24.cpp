#include <iostream>

int main()
{
    int i = 42;
    /* void*可以指向任何类型的对象。 而其他指针类型必须要与所指对象严格匹配 */
    void * p = &i;
    /*  error: invalid conversion from 'int*' to 'long int* */
    long * lp = &i;

    return 0;
}