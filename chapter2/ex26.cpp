#include <iostream>

int main()
{
    /* error: uninitialized const 'buf' */
    const int buf;
    int       cnt = 0;
    const int sz  = cnt;
    ++cnt;
    /* error: increment of read-only variable 'sz' */
    ++sz;

    return 0;
}