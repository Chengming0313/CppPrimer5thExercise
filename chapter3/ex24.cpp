#include <cctype>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/* 这里空vector有bug */
int main()
{
    vector< int > ivec;

    int i;
    while ( cin >> i )
    {
        ivec.push_back( i );
    }

    /* vector长度小于1直接返回 */
    if ( ivec.size() < 1 )
    {
        return 0;
    }

    /* 按顺序输出相邻两个元素的和 */

    for ( auto it = ivec.begin(); it < ivec.end() - 1; ++it )
    {
        cout << *it + *( it + 1 ) << endl;
    }
    cout << "---------------------------" << endl;

    /* 首尾元素求和 */
    auto it2 = ivec.end() - 1;
    for ( auto it = ivec.begin(); it < it2; ++it )
    {
        cout << *it + *( it2-- ) << endl;
    }

    return 0;
}