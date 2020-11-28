#include <iostream>

int main()
{
    /* ip:int* i:int r:i的引用 */
    int *ip, i, &r = i;
    /* i:int ip:空指针  */
    int i, *ip = 0;
    /* ip:int* ip2:int */
    int *ip, ip2;

    return 0;
}