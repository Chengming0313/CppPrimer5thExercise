#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void check_and_print( const vector< int > &ivec )
{
    cout << "size : " << ivec.size() << " [";
    for ( auto begin = ivec.cbegin(); begin != ivec.cend(); ++begin )
    {
        cout << *begin << ( begin == ivec.cend() - 1 ? "]" : ", " );
    }
    cout << endl;
}

void check_and_print( const vector< string > &svec )
{
    cout << "size : " << svec.size() << " [";
    for ( auto begin = svec.cbegin(); begin != svec.cend(); ++begin )
    {
        cout << *begin << ( begin == svec.cend() - 1 ? "]" : ", " );
    }
    cout << endl;
}

int main()
{
    /* 大小为0，直接初始化，没有指定大小，默认为0 */
    vector< int > v1;
    /* 直接初始化，指定大小为10，元素默认为0 */
    vector< int > v2( 10 );
    /* 直接初始化，指定大小和元素 */
    vector< int > v3( 10, 42 );
    /* 列表初始化，1个元素 */
    vector< int > v4{ 10 };
    /* 列表初始化，两个元素 */
    vector< int > v5{ 10, 42 };
    /* 直接初始化，虽然是列表初始化的形式，但是不满足列表初始化，等价于v6(10) */
    vector< string > v6{ 10 };
    /* 直接初始化，等价于v7(10, "hi") */
    vector< string > v7{ 10, "hi" };

    check_and_print( v1 );
    check_and_print( v2 );
    check_and_print( v3 );
    check_and_print( v4 );
    check_and_print( v5 );
    check_and_print( v6 );
    check_and_print( v7 );

    return 0;
}