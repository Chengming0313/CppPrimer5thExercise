#include <iostream>

int main()
{
    int i = 0;
    /* error: cannot convert 'int*' to 'double*' in initialization */
    double * dp = &i;
    /* error: invalid conversion from 'int' to 'int*' [-fpermissive] */
    int * ip = i;
    int * p  = &i;

    return 0;
}