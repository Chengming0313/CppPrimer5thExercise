#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    while ( cin >> s1 )
    {
#if 0
        // 直接拼接
        s2 += s1;
#endif
        // 中间用空格拼接
        s2 = s2 + ( s2 == "" ? "" : " " ) + s1;
    }
    cout << s2 << endl;

    return 0;
}