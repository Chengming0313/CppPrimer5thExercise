#include <iostream>

int main()
{
    int ival = 1.01;
    /* error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int' */
    int & rval1 = 1.01;
    int & rval2 = ival;
    /* error: 'rval3' declared as reference but not initialized */
    int & rval3;

    return 0;
}