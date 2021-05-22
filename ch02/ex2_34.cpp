#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int i = 0, &r = i;
    auto a = r;  // int

    const int ci = 0, &cr = ci;
    auto b  = ci;   // int
    auto c  = cr;   // int
    auto d  = &i;   // int *
    auto e  = &ci;  // const int *
    auto &g = ci;   // const int &

    a = 42;
    b = 42;
    c = 42;
    // d = 42;
    // e = 42;
    // g = 42;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << g << endl;
    return 0;
}