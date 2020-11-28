#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /* 直接初始化 */
    vector< int > ivec1( 10, 42 );
    /* 列表初始化 */
    vector< int > ivec2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
    vector< int > ivec3;

    for ( int i = 0; i < 10; ++i )
    {
        ivec3.push_back( 42 );
    }

    return 0;
}