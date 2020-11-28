#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double dval;
    int    ival;
    int *  pval;
    /* error: invalid conversion from 'int*' to 'int' */
    // dval = ival = pval = 0;
    dval = ival = 0;
    pval        = 0;

    return 0;
}