
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a[2][5];
    for (auto i = 0; i < 2; ++i)
    {
        for (auto j = 0; j < 5; ++j)
        {
            cout << &(a[i][j]) << " ";
        }
    }
    cout << endl;

    return 0;
}