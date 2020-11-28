#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    cin >> s1;
    /* 范围for循环，不使用引用的话无法改变str */
    /* warning: variable 'ch' set but not used */
    for ( char ch : s1 )
    {
        ch = 'X';
    }
    cout << s1 << endl;

    return 0;
}