#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< int > ivec;

    int i;
    while ( cin >> i )
    {
        ivec.push_back( i );
    }
#if 0
    /* 按顺序输出相邻两个元素的和 */
    for ( decltype( ivec.size() ) m = 0; m + 1 < ivec.size(); ++m )
    {
        cout << ivec[ m ] + ivec[ m + 1 ] << endl;
    }
#endif
    /* 按顺序输出首元素和尾元素的和 */
    for ( decltype( ivec.size() ) m = 0, n = ivec.size() - 1; m < n; )
    {
        cout << ivec[ m ] + ivec[ n ] << endl;
        ++m;
        --n;
    }

    return 0;
}