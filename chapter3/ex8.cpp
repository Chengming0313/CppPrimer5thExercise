#include <iostream>
#include <string>

using namespace std;

/* 比起while循环和传统for循环，范围for语句更好，不直接操作索引，更简洁。 */
int main()
{
    string s1;
    cin >> s1;
#if 0
    /* while循环 */
    string::size_type i = 0;
    while ( i < s1.size() )
    {
        s1[ i ] = 'X';
        ++i;
    }
#endif
    /* 传统for循环 */
    for ( decltype( s1.size() ) i = 0; i < s1.size(); ++i )
    {
        s1[ i ] = 'X';
    }
    cout << s1 << endl;

    return 0;
}